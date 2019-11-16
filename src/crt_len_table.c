/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_len_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:39 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 17:36:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

void	ft_put_end(int **roads, int end)
{
	int n;

	n = 0;
	while ((*roads)[n] != DISJ)
		n++;
	(*roads)[n] = end;
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

int		ft_calc_lems(t_paths paths, t_matrix aj,
			int **lems_in_rooms, t_lem_in lem_in)
{
	int	i;
	int	lems;
	int	min;
	int	max_path;
	int	*len_table;

	i = -1;
	lems = lem_in.ants;
	ft_crt_len_table(paths, &len_table, aj, lem_in);
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
