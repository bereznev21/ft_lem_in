/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 19:31:38 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (!find_path(&aj, se))//todo: find_path should delete free memory when path not found
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
