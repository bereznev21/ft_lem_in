/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/13 13:41:54 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	suurballe_reverse_path(t_matrix *aj, t_matrix *path)
{
	int i;
	int j;

	i = -1;
	while (++i < aj->m)
	{
		j = -1;
		while (++j < aj->n)
		{
			if (path->data[i][j])
			{
				aj->data[j][i] = -aj->data[i][j];
				aj->data[i][j] = DISJ;
			}
		}
	}
}

void	remove_sym(t_matrix *path)
{
	int i;
	int j;

	i = -1;
	while (++i < path->m)
	{
		j = i - 1;
		while (++j < path->n)
		{
			if (path->data[i][j] == 1 && path->data[j][i] == 1)
			{
				path->data[i][j] = 0;
				path->data[j][i] = 0;
			}
		}
	}
}

int		path_step(t_matrix *path, int k)
{
	int j;

	j = -1;
	while (++j < path->n)
		if (path->data[k][j])
			return (j);
	return (-1);
}

void	split_path_node(t_matrix *aj, int k, int prev, int next)
{
	int i;
	int n;

	n = aj->n;
	t_matrix_duplicate_row(aj, k, aj->m);
	t_matrix_duplicate_col(aj, k, aj->n);
	i = -1;
	while (++i < aj->n)
	{
		if (i != prev)
			aj->data[k][i] = DISJ;
		if (i != next)
			aj->data[i][n] = DISJ;
	}
	aj->data[n][k] = 0;
}

void	split_paths_nodes(t_matrix *aj, t_matrix *paths,
							t_collapse *c, t_startend se)
{
	int j;
	int k_prev;
	int k_next;
	int k;
	int size;

	size = aj->m;
	j = -1;
	while (++j < size)
	{
		if (!paths->data[se.start][j])
			continue;
		k_prev = se.start;
		k = j;
		while (k != se.end)
		{
			k_next = path_step(paths, k);
			split_path_node(aj, k, k_prev, k_next);
			t_collapse_add(c, k);
			k_prev = aj->m - 1;
			k = k_next;
		}
	}
}

/*
** http://www.macfreek.nl/memory/Disjoint_Path_Finding
*/

int		suurballe_next(t_matrix aj, t_matrix *all_paths, t_startend se)
{
	t_collapse	c;
	t_matrix	path;

	aj = t_matrix_copy(&aj);
	suurballe_reverse_path(&aj, all_paths);
	t_collapse_init(&c, aj.m);
	split_paths_nodes(&aj, all_paths, &c, se);
	if (!find_path(&aj, &path, se)) //todo: find_path should delete free memory when path not found
	{
		t_matrix_del(&aj);
		t_array_del(&c.a);
		return (0);
	}
	t_collapse_do(&c, &path);
	t_array_del(&c.a);
	*all_paths = t_matrix_add(all_paths, &path);
	remove_sym(all_paths);
	t_matrix_del(&aj);
	t_matrix_del(&path);
	return (1);
}

int		suurballe(t_matrix *aj, t_matrix *all_paths, t_startend se)
{
	int			i;

	t_matrix_init_zero(all_paths, aj->m, aj->n);
	i = 0;
	while (suurballe_next(*aj, all_paths, se))
		i++;
	return (i);
}

int		lem_in_count_steps(t_matrix *all_paths, t_lem_in lem_in)
{
	int			i;
	int			max;
	int			*len_table;
	int			*lems_in_rooms;
	t_matrix	paths_table;

	t_matrix_init(&paths_table, all_paths->m_alloc, all_paths->n_alloc);
	ft_crt_len_table(*all_paths, lem_in, &paths_table, &len_table);
	ft_calc_lems(*all_paths, lem_in, len_table, &lems_in_rooms);
//	printf("\n%d", len_table[0] + lems_in_rooms[0]);
/*
	putchar('\n');
	ft_print_arr(len_table, all_paths->n);
	putchar('\n');
	ft_print_arr(lems_in_rooms, all_paths->n);
	putchar('\n');
*/
	i = ft_srch_max1(len_table, all_paths->n);
	max = len_table[i];
//	printf("%d\n", max);
	return (max);
}

int		lem_in_solve(t_matrix *aj, t_matrix *all_paths, t_lem_in lem_in)
{
	int	steps;
	int	steps_result;
	int	status;
	int i;

	steps_result = INT_MAX;
	t_matrix_init_zero(all_paths, aj->m, aj->n);
	i = -1;
	while(++i < lem_in.ants)
	{
		if (lem_in.flags & FLAG_DEBUG)
			printf("path %d...\n", i + 1);
		status = suurballe_next(*aj, all_paths, lem_in.se);
		if (!status)
			break;
		steps = lem_in_count_steps(all_paths, lem_in);
		if (steps_result < steps)
			return (steps_result);
		steps_result = steps;
	}
	return (steps_result);
}
