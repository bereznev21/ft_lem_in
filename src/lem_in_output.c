/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/03 20:11:17 by rpoetess         ###   ########.fr       */
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

int		ft_got_path(t_lem_in lem_in, t_matrix paths, int **paths_table, int i)
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
				ft_put_end(paths_table, begin);
				//printf("|%d|\n", j);
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

void	ft_crt_len_table(t_matrix paths, t_lem_in lem_in, t_matrix *paths_table, int **len_table)
{
	int j;
	int	num_path;


	j = -1;
	num_path = 0;
	//t_matrix_init(len_table, paths.m, paths.n);
	(*len_table) = (int*)malloc(sizeof(int) * paths.m);
	while (++j < paths.m)
		(*len_table)[j] = -1;
	j = -1;
	while (++j < paths.n)
	{
		if (paths.data[lem_in.start][j] == 1)
		{
			//printf("%d\n", num_path);
			(*len_table)[num_path] = ft_got_path(lem_in , paths, &paths_table->data[num_path], j);
			//printf("%d ", *(rooms_table->data)[num_path]);
			num_path++;
		}
	}
	//printf("\n");
	(*len_table)[num_path] = -1;
}
/*
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
*/
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

void	ft_print_arr(int *lems_in_rooms, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", lems_in_rooms[i]);
		i++;
	}
}

void	ft_calc_lems(t_matrix paths, t_lem_in lem_in, int *len_table, int **lems_in_rooms)
{
	int		lems;
	int		min;
	int		i;
	int		j;

	j = -1;
	i = 0;
	min = 0;
	lems = lem_in.ants;
	*lems_in_rooms = (int*)malloc(sizeof(int) * paths.n);
	while (++j < paths.n)
		(*lems_in_rooms)[j] = 0;
	while (lems)
	{
		while (len_table[i] != -1 && lems)
		{
			min = ft_srch_min(len_table);
			(*lems_in_rooms)[min]++;
			len_table[min]++;
			//printf("%d ", min);
			i++;
			lems--;
		}
		//printf("\n");
		i = 0;
	}
}

void	ft_move_leams_in_path(t_matrix *condition_of_ants, t_matrix paths_table, int k)
{
	(void)condition_of_ants;
	(void)paths_table;
	(void)k;
	int i;

	i = paths_table.n;
	while (i > 0)
	{
		//printf("%d ", paths_table.data[k][i]);
		if (paths_table.data[k][i] != DISJ || i == paths_table.n)
			condition_of_ants->data[k][i] = condition_of_ants->data[k][i - 1];
		//	ft_memmove(condition_of_ants->data[k][1], condition_of_ants->data[k][0], paths_table.n);
		i--;
	}
	condition_of_ants->data[k][0] = 0;
}

void	ft_print_ants(t_matrix	condition_of_ants, t_matrix paths_table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < condition_of_ants.m && condition_of_ants.data[i][j] != DISJ)
	{
		while (j < condition_of_ants.n && condition_of_ants.data[i][j] != DISJ)
		{
			if (condition_of_ants.data[i][j] != 0)
			{
				if (i > 0)
					printf(" ");
				printf("L%d-%d", condition_of_ants.data[i][j], paths_table.data[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("\n");
}

void	ft_print_lems(int *lems_in_rooms, t_matrix paths, t_matrix paths_table, int ants)
{
	int			i;
	int			lem_num;
	t_matrix	condition_of_ants;

	lem_num = 0;
	i = 0;
	(void)paths_table;
	t_matrix_init(&condition_of_ants, paths.m, paths.n);
	//printf("\n");
	while (ants > 0)
	{
		while (i < paths.n)
		{
			ft_move_leams_in_path(&condition_of_ants, paths_table, i);
			if (lems_in_rooms[i] > 0 && ants > 0)
			{
				//printf("%d ", i);
				lem_num++;
				//ft_push_lem(&condition_of_ants, paths_table, i, lem_num);
				condition_of_ants.data[i][0] = lem_num;
				lems_in_rooms[i]--;
				ants--;
			}
			i++;
		}
		//t_matrix_print(&condition_of_ants);
		ft_print_ants(condition_of_ants, paths_table);
		i = 0;
	}
	//t_matrix_print(&condition_of_ants);
}

void	lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in)
{
	int			i;
	int			*len_table;
	int			*lems_in_rooms;
	t_matrix	paths_table;

	i = -1;
	t_matrix_init(&paths_table, aj.m, aj.n);
	ft_crt_len_table(paths, lem_in, &paths_table, &len_table);
//	t_matrix_print(&paths_table);
//	printf("\n");
	//ft_print_arr(len_table, paths.n);
	ft_calc_lems(paths, lem_in, len_table, &lems_in_rooms);
//	printf("\n");
	//ft_print_arr(lems_in_rooms, paths.n);
	ft_print_lems(lems_in_rooms, paths, paths_table, lem_in.ants);
	//size_paths = ft_srh_num_paths(paths, &len, num_patchs);
	//ft_print_paths(paths, size_paths, num_patchs, lems);
}
