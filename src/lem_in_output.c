/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 15:56:50 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_srch_max_paths_in_rooms(int *len_table, int len)
{
	int max;
	int i;
	int	i_max;

	i = -1;
	i_max = 0;
	max = len_table[0];
	while (i < len && len_table[++i] != -1)
	{
		if (len_table[i] < max)
		{
			max = len_table[i];
			i_max = i;
		}
	}
	return (max);
}

void	ft_calc_lems(t_matrix paths, t_lem_in lem_in,
			int *len_table, int **lems_in_rooms)
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
			i++;
			lems--;
		}
		i = 0;
	}
	//ft_free_matrix(&paths);
}

void	ft_move_leams_in_path(t_matrix *condition_of_ants,
			t_matrix paths_table, int k)
{
	int i;

	i = paths_table.n;
	while (i > 0)
	{
		if (paths_table.data[k][i] != DISJ || i == paths_table.n)
			condition_of_ants->data[k][i] = condition_of_ants->data[k][i - 1];
		i--;
	}
	condition_of_ants->data[k][0] = 0;
}

void	lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in)
{
	int			i;
	int			max_path;
	int			*len_table;
	int			*lems_in_rooms;
	t_matrix	paths_table;

	i = -1;
	(void)lems_in_rooms;
	t_matrix_init(&paths_table, aj.m, aj.n);
	ft_crt_len_table(paths, lem_in, &paths_table, &len_table);
	max_path = ft_srch_max_paths_in_rooms(len_table, aj.m);
	ft_calc_lems(paths, lem_in, len_table, &lems_in_rooms);
	ft_print_lems(lems_in_rooms, paths_table, lem_in, max_path);
}
