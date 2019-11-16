/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:49 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 17:11:25 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include "libft/includes/libft.h"

void	ft_init_arr_1(int **arr, int len)
{
	int	i;

	i = -1;
	*arr = (int*)malloc(sizeof(int) * (len));
	while (++i < len)
		(*arr)[i] = DISJ;
}

int		**ft_init_arr_2_zero(int m, int n)
{
	int	i;
	int	j;
	int	**tmp;

	tmp = (int**)malloc(sizeof(int*) * (m));
	i = -1;
	while (++i < m)
	{
		tmp[i] = (int*)malloc(sizeof(int) * (n));
		j = -1;
		while (++j < n)
			tmp[i][j] = DISJ;
	}
	return (tmp);
}

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

void	ft_crt_len_table1(t_paths paths, int **len_table,
			t_matrix aj, t_lem_in lem_in)
{
	int	i;

	i = -1;
	ft_init_arr_1(len_table, aj.m);
	while (paths.paths[++i])
		(*len_table)[i] = ft_got_path1(paths.paths[i], lem_in);
}

int		ft_calc_lems1(t_paths paths, t_matrix aj,
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
	return (len_table[max_path]);
}

int		ft_srch_prev_room(int *path, int index)
{
	int i;

	i = 0;
	while (path[i] != index)
		i++;
	return (i);		
}

void	ft_move_lems_in_path1(int **condition_of_ants, int **path, t_startend se)
{
	int	endl;
	int	prev;

	endl = se.end;
	prev = ft_srch_prev_room(*path, endl);
	//printf("%d ", prev);
	while (endl != se.start)
	{
		//if ((*condition_of_ants)[prev] != DISJ)
		{
			//printf("%d\n", prev);
			(*condition_of_ants)[endl] = (*condition_of_ants)[prev];
		}
		endl = prev;
		if (prev != se.start)
			prev = ft_srch_prev_room(*path, endl);
	}
	(*condition_of_ants)[endl] = DISJ;
//	ft_putchar('\n');
//	ft_print_arr(*condition_of_ants, 7);
	//ft_putchar('\n');
	/*
	ft_putchar('\n');
	ft_print_arr(*condition_of_ants, 7);
	ft_putchar('\n');
	*/
}

int		**ft_move_lems3(t_paths paths, int **condition_of_ants,
			int **lems_in_rooms, int *ants)
{
	int	lem_num;
	int	i;

	lem_num = 0;
	i = -1;
	while (paths.paths[++i])
	{
		//ft_move_lems_in_path1(&condition_of_ants[i], &paths.paths[i], paths.se);
		condition_of_ants[i][paths.se.start] = DISJ;
		if ((*lems_in_rooms)[i] > 0 && *ants > 0)
		{
			lem_num++;
			//printf("%d ", lem_num);
			condition_of_ants[i][paths.se.start] = lem_num;
			(*lems_in_rooms)[i]--;
			(*ants)--;
		}
	}
	/*
	ft_putchar('\n');
	ft_print_arr(condition_of_ants[0], paths.size);
	ft_putchar('\n');
	ft_print_arr(condition_of_ants[1], paths.size);
	ft_putchar('\n');
	*/
	return (condition_of_ants);
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

void	ft_print_lems2(int *lems_in_rooms,
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
			ft_move_lems_in_path1(&condition_of_ants[i], &paths.paths[i], paths.se);
			//condition_of_ants[i][paths.se.start] = DISJ;
			if (lems_in_rooms[i] > 0 && ants > 0)
			{
				lem_num++;
				//printf("%d ", lem_num);
				condition_of_ants[i][paths.se.start] = lem_num;
				lems_in_rooms[i]--;
				(ants)--;
			}
		}
		//condition_of_ants = ft_move_lems3(paths, condition_of_ants, &lems_in_rooms, &ants);
		ft_print_ants1(condition_of_ants, paths.paths, lem_in);
		max_path--;
		ft_putchar('\n');
	}
	//printf("%d", max_path);
	if (max_path > 0)
		while (max_path >= 0)
		{
			i = -1;
			while (paths.paths[++i])
				ft_move_lems_in_path1(&condition_of_ants[i], &paths.paths[i], paths.se);
			ft_print_ants1(condition_of_ants, paths.paths, lem_in);
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

	max_path = ft_calc_lems1(paths, aj, &lems_in_rooms, lem_in);
	ft_putchar('\n');
	ft_print_lems2(lems_in_rooms, paths, lem_in, max_path);
}
