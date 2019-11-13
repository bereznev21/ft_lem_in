/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_len_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:39 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/13 17:25:44 by rpoetess         ###   ########.fr       */
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

void	ft_crt_len_table(t_matrix paths, t_lem_in lem_in, t_matrix *paths_table, int **len_table)
{
	int j;
	int	num_path;

	j = -1;
	num_path = 0;
	(*len_table) = (int*)malloc(sizeof(int) * (paths.m));
	while (++j < paths.m)
		(*len_table)[j] = DISJ;
	j = -1;
	while (++j < paths.n)
		if (paths.data[lem_in.se.start][j] == 1)
		{
			(*len_table)[num_path] = ft_got_path(lem_in, paths, &paths_table->data[num_path], j);
			num_path++;
		}
	printf("%d\n", num_path);
	(*len_table)[num_path] = -1;
}
