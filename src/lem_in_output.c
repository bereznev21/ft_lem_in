/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:49 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/17 17:58:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include "libft/includes/libft.h"

int		ft_got_path1(int *path, t_lem_in lem_in)
{
	int	begin;
	int	len_path;

	len_path = 0;
	begin = lem_in.se.start;
	while (begin != lem_in.se.end)
	{
		begin = path[begin];
		len_path++;
	}
	return (len_path);
}

void	ft_crt_len_table(t_paths paths, int **len_table,
			t_matrix aj, t_lem_in lem_in)
{
	int	i;

	i = -1;
	ft_init_arr_1(len_table, aj.m);
	while (paths.paths[++i])
		(*len_table)[i] = ft_got_path1(paths.paths[i], lem_in);
}

int		ft_srch_prev_room(int *path, int index, t_startend se, t_paths paths)
{
	int i;

	i = 0;
	(void)se;
	(void)paths;
	while (path[i] != index)
		i++;
	//if (index == se.start)
	//	return (se.start);
	return (i);
}

void	ft_move_lems_in_path1(int **condition_of_ants,
			int **path, t_startend se, t_paths paths)
{
	int	endl;
	int	prev;

	endl = se.end;
	prev = ft_srch_prev_room(*path, endl, se, paths);
	while (1)
	{
		(*condition_of_ants)[endl] = (*condition_of_ants)[prev];
		endl = prev;
		//printf("%d\n", prev);
		if (prev == se.start)
			break;
		prev = ft_srch_prev_room(*path, endl, se, paths);
	}
	(*condition_of_ants)[endl] = DISJ;
}

/*
void	ft_move_lems_in_path1(int **condition_of_ants,
			int **path, t_startend se, t_paths paths)
{
	int	room1;
	int	room2;
	int	ant;

	(void)paths;
	room1 = se.start;
	ant = (*condition_of_ants)[room1];
	while (room1 != se.end)
	{
		(*condition_of_ants)[room1] = ant;
		room2 = (*path)[room1];
		ant = (*condition_of_ants)[room2];
		(*condition_of_ants)[room2] = (*condition_of_ants)[room1];
		room1 = room2;
	}
	//ft_print_arr(*condition_of_ants, paths.size);
	(*condition_of_ants)[se.start] = DISJ;
}
*/
void	ft_print_ants(int **condition_of_ants, int **paths, t_lem_in lem_in)
{
	int	begin;
	int	i;
	int	num;

	i = -1;
	while (paths[++i])
	{
		begin = lem_in.se.start;
		while (begin != lem_in.se.end)
		{
			if (condition_of_ants[i][begin] != DISJ)
			{
				num = paths[i][begin];
				ft_print_ans(condition_of_ants[i][begin],
					((t_room*)t_array_get(&lem_in.rooms, num))->name);
			}
			begin = paths[i][begin];
		}
	}
}

void	ft_print_lems(int *lems_in_rooms,
			t_paths paths, t_lem_in lem_in, int max_path)
{
	int	i;
	int	ants;
	int	len;
	int	lem_num;
	int	**condition_of_ants;

	lem_num = 0;
	len = 0;
	ants = lem_in.ants;
	while (paths.paths[len])
		len++;
	condition_of_ants = ft_init_arr_2_zero(len, paths.size);
	while (ants > 0)
	{
		i = -1;
		while (paths.paths[++i])
		{
			ft_move_lems_in_path1(&condition_of_ants[i],
				&paths.paths[i], paths.se, paths);
			if (lems_in_rooms[i] > 0 && ants > 0)
			{
				lem_num++;
				condition_of_ants[i][paths.se.start] = lem_num;
				lems_in_rooms[i]--;
				(ants)--;
			}
		}
		ft_print_ants(condition_of_ants, paths.paths, lem_in);
		max_path--;
		ft_putchar('\n');
	}
	if (max_path > 0)
		while (max_path >= 0)
		{
			i = -1;
			while (paths.paths[++i])
				ft_move_lems_in_path1(&condition_of_ants[i],
					&paths.paths[i], paths.se, paths);
			ft_print_ants(condition_of_ants, paths.paths, lem_in);
			max_path--;
			if (max_path > 0)
				ft_putchar('\n');
		}
	//ft_free_matrix(&condition_of_ants);
}

void	lem_in_output(t_paths paths, t_matrix aj, t_lem_in lem_in)
{
	int	max_path;
	int	*lems_in_rooms;

	max_path = ft_calc_lems(paths, aj, &lems_in_rooms, lem_in);
	ft_putchar('\n');
	ft_print_lems(lems_in_rooms, paths, lem_in, max_path);
}
