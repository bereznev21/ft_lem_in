/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:49 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/15 18:57:43 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/includes/libft.h"

void	ft_init_arr_1(int **arr, int len)
{
	int	i;

	i = -1;
	*arr = (int*)malloc(sizeof(int) * (len));
	while (++i < len)
		(*arr)[i] = DISJ;
}

int		**ft_init_arr_2_zero(int len)
{
	int	i;
	int	j;
	int	**tmp;

	tmp = (int**)malloc(sizeof(int*) * (len));
	i = -1;
	while (++i < len)
	{
		tmp[i] = (int*)malloc(sizeof(int) * (100));
		j = -1;
		while (++j < 100)
			tmp[i][j] = 0;
	}
	return (tmp);
}

int		ft_got_path1(int *path, t_lem_in lem_in, t_matrix aj)
{
	int	j;
	int	begin;
	int	len_path;

	len_path = 0;
	begin = lem_in.se.start;
	while (begin != lem_in.se.end)
	{
		j = -1;
		while (++j < aj.m)
		{
			begin = path[begin];
			len_path++;
		}
	}
	return (len_path);
}

void	ft_crt_len_table1(int **paths, int **len_table,
			t_matrix aj, t_lem_in lem_in)
{
	int	i;

	i = -1;
	ft_init_arr_1(len_table, aj.m);
	while (paths[++i])
		(*len_table)[i] = ft_got_path1(paths[i], lem_in, aj);
}

int		ft_calc_lems1(int **paths, t_matrix aj,
			int **lems_in_rooms, t_lem_in lem_in)
{
	int	i;
	int	lems;
	int	min;
	int	max_path;
	int	*len_table;

	i = -1;
	lems = lem_in.ants;
	ft_crt_len_table1(paths, &len_table, aj, lem_in);
	*lems_in_rooms = (int*)malloc(sizeof(int) * aj.n);
	while (++i < aj.n)
		(*lems_in_rooms)[i] = 0;
	while (lems)
	{
		i = -1;
		while (++i < aj.m && lems)
		{
			min = ft_srch_min(len_table);
			(*lems_in_rooms)[min]++;
			len_table[min]++;
			lems--;
		}
	}
	max_path = ft_srch_max1(*lems_in_rooms, aj.m);
	return (max_path);
}

int		ft_srch_prev_room(int *path, int index)
{
	int i;

	i = 0;
	while (path[i] != index)
		i++;
	return (i);		
}

void	ft_move_lems_in_path1(int *condition_of_ants, int **path, t_lem_in lem_in)
{
	int	endl;
	int	prev;

	endl = lem_in.se.end;
	prev = ft_srch_prev_room(*path, endl);
	while (prev != lem_in.se.start)
	{
		if (condition_of_ants[endl] > 0)
			condition_of_ants[endl] = condition_of_ants[prev];
		endl = prev;
		prev = ft_srch_prev_room(*path, endl);
	}
	condition_of_ants[prev] = 0;
}

int		ft_print_lems3(int **paths, int **condition_of_ants,
			int *lems_in_rooms, t_lem_in lem_in)
{
	int	ants;
	int	lem_num;
	int	i;

	lem_num = 0;
	i = -1;
	ants = lem_in.ants;
	while (paths[++i])
	{
		ft_move_lems_in_path1(condition_of_ants[i], &paths[i], lem_in);
		if (lems_in_rooms[i] > 0 && ants > 0)
		{
			lem_num++;
			condition_of_ants[i][lem_in.se.start] = lem_num;
			lems_in_rooms[i]--;
			ants--;
		}
	}
	return (ants);
}

void	ft_print_ants1(int **condition_of_ants, int **paths, t_lem_in lem_in)
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
			num = paths[i][begin];
			ft_print_ans(condition_of_ants[i][begin],
				((t_room*)t_array_get(&lem_in.rooms, num))->name);
		}
	}
}

void	ft_print_lems2(int *lems_in_rooms,
			int **paths, t_lem_in lem_in, int max_path)
{
	int	i;
	int	ants;
	int	len;
	int	**condition_of_ants;

	i = -1;
	len = 0;
	ants = lem_in.ants;
	while (paths[len])
		len++;
	condition_of_ants = ft_init_arr_2_zero(len);
	while (ants > 0)
	{
		ants = ft_print_lems3(paths, condition_of_ants, lems_in_rooms, lem_in);
		ft_print_ants1(condition_of_ants, paths, lem_in);
		max_path--;
		ft_putchar('\n');
	}
	if (max_path > 0)
		while (max_path >= 0)
		{
			i = -1;
			while (paths[++i])
				ft_move_lems_in_path1(condition_of_ants[i], &paths[i], lem_in);
			ft_print_ants1(condition_of_ants, paths, lem_in);
			if (max_path > 0)
				ft_putchar('\n');
			max_path--;
		}
	//ft_free_matrix(&condition_of_ants);
}

void	lem_in_output(int **paths, t_matrix aj, t_lem_in lem_in)
{
	int	max_path;
	int	*lems_in_rooms;

	max_path = ft_calc_lems1(paths, aj, &lems_in_rooms, lem_in);
	ft_putchar('\n');
	ft_print_lems2(lems_in_rooms, paths, lem_in, max_path);
}
