/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_len_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:39 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 14:25:26 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

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

int		ft_got_path(t_lem_in lem_in, t_matrix paths, int **paths_table, int i)
{
	int	j;
	int	begin;
	int len_path;

	len_path = 0;
	begin = i;
	while (1)
	{
		j = -1;
		while (++j < paths.m)
			if (paths.data[begin][j] == 1)
			{
				ft_put_end(paths_table, begin);
				begin = j;
				len_path++;
				break ;
			}
		if (begin == lem_in.se.end)
		{
			ft_put_end(paths_table, begin);
			break ;
		}
	}
	return (len_path);
}

void	ft_calc_lems1(int *len_table, int **lems_in_rooms,
			t_lem_in lem_in, t_matrix aj)
{
	int	lems;
	int	min;
	int	i;

	i = -1;
	lems = lem_in.ants;
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
}

int		ft_calc_lems(t_paths paths, t_matrix aj,
			int **lems_in_rooms, t_lem_in lem_in)
{
	int	i;
	int	max_path;
	int	*len_table;

	i = -1;
	ft_crt_len_table(paths, &len_table, aj, lem_in);
	*lems_in_rooms = (int*)malloc(sizeof(int) * aj.n);
	while (++i < aj.n)
		(*lems_in_rooms)[i] = 0;
	ft_calc_lems1(len_table, lems_in_rooms, lem_in, aj);
	max_path = ft_srch_max1(*lems_in_rooms, aj.m);
	max_path = len_table[max_path];
	free(len_table);
	return (max_path);
}
