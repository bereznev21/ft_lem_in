/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/13 14:02:54 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"
#include "libft/includes/libft.h"

int		*ft_srh_num_paths(int **paths, int *len, int num_patchs)
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

void	ft_calc_lems(t_matrix paths, t_lem_in lem_in,
			int *len_table, int **lems_in_rooms)
{
	int		lems;
	int		min;
	int		i;
	int		j;

	(void)min;
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
			i++;
			lems--;
		}
		i = 0;
	}
//	ft_free_matrix(&paths);
}

void	ft_move_leams_in_path(t_matrix *condition_of_ants,
			t_matrix paths_table, int k)
{
	int i;

	i = paths_table.n - 1;
	//printf("%d\n", i);
	while (i > 0)
	{
		if (paths_table.data[k][i] != DISJ)
			condition_of_ants->data[k][i] = condition_of_ants->data[k][i - 1];
		i--;
	}
	condition_of_ants->data[k][0] = 0;
	//t_matrix_print(condition_of_ants);
}

void	lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in)
{
	int			max_path;
	int			*len_table;
	int			*lems_in_rooms;
	t_matrix	paths_table;

	t_matrix_init(&paths_table, aj.m, aj.n);
	ft_crt_len_table(paths, lem_in, &paths_table, &len_table);
//	ft_print_arr(len_table, aj.m);
//	ft_putchar('\n');
	ft_calc_lems(paths, lem_in, len_table, &lems_in_rooms);
	max_path = ft_srch_max1(lems_in_rooms, aj.m);
//	ft_putchar('\n');
//	ft_print_arr(len_table, aj.m);
//	ft_putchar('\n');
//	ft_print_arr(lems_in_rooms, aj.m);
//	max_path += lems_in_rooms[ft_srch_max1(len_table, aj.m)];
	ft_putnbr(len_table[max_path]);
	ft_putchar('\n');
	ft_print_lems(lems_in_rooms, paths_table, lem_in, len_table[max_path]);
	t_matrix_del(&paths_table);
	free(len_table);
	free(lems_in_rooms);
}
