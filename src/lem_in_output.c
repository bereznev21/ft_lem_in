/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/01 23:05:15 by rpoetess         ###   ########.fr       */
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
	return (len_path);
}

void	ft_crt_len_table(t_matrix paths, t_lem_in lem_in, t_matrix *rooms_table, int **len_table)
{
	int j;
	int	num_path;

	j = 0;
	num_path = 0;
	//t_matrix_init(len_table, paths.m, paths.n);
	(*len_table) = (int*)malloc(sizeof(int) * paths.m);
	while (j < paths.n)
	{
		if (paths.data[lem_in.start][j] == 1)
		{
			//ft_strjoin_str();
			(*len_table)[num_path] = ft_got_path(lem_in , paths, rooms_table->data[num_path], j);
			//printf("%d\n", (*len_table)[num_path]);
			num_path++;
		}
		j++;
	}
	(*len_table)[num_path] = -1;
}

void	ft_srch_border(int *len_table, int ants, int *border)
{
	int	i;
	int	sum;
	int	k;

	sum = 0;
	i = 0;
	k = 0;
	(void)border;
	(void)len_table;	
	if (ants > 0)
	{
		while (len_table[i] > 0)
		{
			//printf("%d\n", len_table[i]);
			//printf("%d\n", i);
			if (len_table[i] < ants - k)
				k++;
			//sum++;
			i++;
		}
		*border = k;
	}
}

/*
void	ft_calc_lems(t_matrix paths, t_lem_in lem_in, t_matrix rooms_table, int *len_table)
{
	int			sum;
	int			i;
	int			j;
	int			*calc_table;
	t_matrix	matrix_patch;
	int			border;

	i = 0;
	j = 0;
	sum = 0;
	(void)len_table;
	(void)rooms_table;
	(calc_table) = (int*)malloc(sizeof(int) * paths.m);
	t_matrix_init_zero(&matrix_patch, paths.m, paths.n);
	ft_bzero(calc_table, paths.n);
	border = 0;
	while (sum < lem_in.ants)
	{
		ft_srch_border(len_table, lem_in.ants - sum, &border);
		printf("%d\n", border);
		//exit(0);
		while (sum < lem_in.ants && j < border)
		{
			matrix_patch.data[i][j] = 1;
			sum++;
			j++;
		}
		i++;
		if (i == paths.m)
			continue ;
		j = 0;
	}
	t_matrix_print(&matrix_patch);
}
*/

int		ft_srch_min(int *len_table)
{
	int min;
	int i;
	int	i_min;

	i = -1;
	i_min = 0;
	min = len_table[0];
	//printf("min %d", min);
	while (len_table[++i] != -1)
	{
		//printf("%d ", len_table[i]);
		if (len_table[i] < min)
		{
			min = len_table[i];
			i_min = i;
		}
	}
	return (i_min);
}

void	ft_calc_lems(t_matrix paths, t_lem_in lem_in, t_matrix rooms_table, int *len_table)
{
	(void)rooms_table;
	(void)paths;

	int		lems;
	int		min;
	int		i;
	int		*lems_in_rooms;
	int		j;

	j = -1;
	i = 0;
	min = 0;
	lems = lem_in.ants;
	lems_in_rooms = (int*)malloc(sizeof(int) * paths.n);
	while (++j < paths.n)
		lems_in_rooms[j] = 0;
	while (lems)
	{
		while (len_table[i] != -1 && lems)
		{	
			min = ft_srch_min(len_table);
			lems_in_rooms[min]++;
			len_table[min]++;
			//printf("%d ", min);
			i++;
			lems--;
		}
		//printf("\n");
		i = 0;
	}
	printf("%d\n", lems_in_rooms[0]);
	printf("%d\n", lems_in_rooms[1]);
}

void	lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in)
{
	int			i;
	int			*len_table;
	t_matrix	rooms_table;

	i = -1;
//	(void)aj;
//	len_table = NULL;
	t_matrix_init(&rooms_table, aj.m, aj.n);
	ft_crt_len_table(paths, lem_in, &rooms_table, &len_table);
	//ft_sort_paths(paths);
	//t_matrix_print(&rooms_table);
	ft_calc_lems(paths, lem_in, rooms_table, len_table);
	//ft_calc_lems(paths, lem_in, rooms_table, len_table);
	//size_paths = ft_srh_num_paths(paths, &len, num_patchs);
	//ft_print_paths(paths, size_paths, num_patchs, lems);
}
