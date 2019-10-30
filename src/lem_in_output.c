/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/30 21:30:18 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void		ft_sort_paths(int **paths, int *size_paths, int num_patchs, int lems)
{
	int	i;

	i = 0;
	(void)paths;
	while (i < num_patchs)
	{
		if (size_paths[i] < lems)
			while (lems--)
			{
				/* code */
			}
	}
	
}

int			*ft_srh_num_paths(int **paths, int *len, int num_patchs)
{
	int	i;
	int	*size_paths;

	i = 0;
	size_paths = (int*)malloc(sizeof(int) * num_patchs);
	while (i < num_patchs)
	{
		while (paths[i][*len] != -1)
			(*len)++;

		size_paths[i] = *len;
		i++;
	}
	return (size_paths);
}

int		ft_got_path(t_lem_in lem_in, t_matrix paths, int *rooms_table, int i)
{
	int	j;
	int	begin;
	int len_path;

	len_path = 0;
	begin = i;
	while (begin != lem_in.end)
	{
		j = 0;
		while (j < paths.m)
		{
			if (paths.data[begin][j] == 1)
			{
				ft_put_end(rooms_table, begin);
				begin = j;
				len_path++;
				break;
			}
			j++;
		}
		if (j == paths.m)
			return (0);
	}
	return (j);
}

void	ft_crt_len_table(t_matrix paths, t_lem_in lem_in, t_matrix *rooms_table, int *len_table)
{
	int j;
	int	num_path;

	j = 0;
	num_path = 0;
	//t_matrix_init(len_table, paths.m, paths.n);
	len_table = (int*)malloc(sizeof(int) * paths.m);
	while (j < paths.n)
	{
		if (paths.data[lem_in.start][j] == 1)
		{
			//ft_strjoin_str();
			len_table[num_path] = ft_got_path(lem_in , paths, rooms_table->data[num_path], j);
			num_path++;
		}
		j++;
	}
}

void	lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in)
{
	int			i;
	int			*len_table;
	t_matrix	rooms_table;

	i = 0;
	(void)aj;
	len_table = NULL;
	t_matrix_init(&rooms_table, aj.m, aj.n);
	ft_crt_len_table(paths, lem_in, &rooms_table, len_table);
	t_matrix_print(&rooms_table);
	//ft_sort_paths(paths);
	//size_paths = ft_srh_num_paths(paths, &len, num_patchs);
	//ft_print_paths(paths, size_paths, num_patchs, lems);
}
