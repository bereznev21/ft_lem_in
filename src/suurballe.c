/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 17:57:16 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void split_node(t_matrix *aj, int k)
{
	int i;

	t_matrix_duplicate_node(aj, k, k);
	// k'th is IN; k+1'th us OUT
	for (i = 0; i < aj->n; i++)
	{
		aj->data[k][i] = DISJ; // remove all outs for input node
		aj->data[i][k + 1] = DISJ; //remove all inputs from output node
	}
	aj->data[k][k + 1] = 0; // link between split
}

void split_path_nodes(t_matrix *aj, t_matrix *path,
					  t_matrix *collapser, int *start, int *end)
{
	int i;
	t_matrix path_diag;

	path_diag = t_matrix_copy(path);
	t_matrix_t(&path_diag);
	path_diag = t_matrix_mul(&path_diag, path);
	i = -1;
	while (++i < path_diag.n)
		if (path_diag.data[i][i] == 1 && i != *start && i != *end)
		{
			if (*start > i)
				(*start)++;
			if (*end > i)
				(*end)++;
			t_matrix_duplicate_node(&path_diag, i, i);
			t_matrix_duplicate_row(collapser, i, i);
			split_node(aj, i);
			i++;
		}
}

void collapse(t_matrix *aj, t_matrix *collapser)
{
	int i;
	t_matrix r;

	r = t_matrix_mul(aj, collapser);
	t_matrix_del(aj);
	*aj = r;
	t_matrix_t(collapser);
	r = t_matrix_mul(collapser, aj);
	t_matrix_del(aj);
	*aj = r;
	i = -1;
	while (++i < aj->n)
		aj->data[i][i] = 0;
	t_matrix_del(collapser);
}

void suurballe_reverse_path(t_matrix *aj, t_matrix *path)
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

void remove_sym(t_matrix *path)
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

int path_step(t_matrix *path, int k)
{
	int j;

	j = -1;
	while (++j < path->n)
		if (path->data[k][j])
			return (j);
	return (-1);
}

void split_path_node(t_matrix *aj, int k, int prev, int next)
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

void split_paths_nodes(t_matrix *aj, t_matrix *paths,
					   t_matrix *collapser, int start, int end)
{
	int j;
	int k_prev;
	int k_next;
	int k;
	int size;

	size = aj->m;
	for (j = 0; j < size; ++j)
	{
		if (!paths->data[start][j])
			continue;
		k_prev = start;
		k = j; //path cursor;
		while (k != end)
		{
			k_next = path_step(paths, k);
			split_path_node(aj, k, k_prev, k_next);
			t_matrix_duplicate_row(collapser, k, collapser->m);
			k_prev = aj->m - 1;
			k = k_next;
		}
	}
}

// http://www.macfreek.nl/memory/Disjoint_Path_Finding
int suurballe(t_matrix *aj, t_matrix *all_paths, int start, int end)
{
	t_matrix collapser;
	t_matrix path;
	t_matrix aj2;
	int i;

	t_matrix_init_zero(all_paths, aj->m, aj->n);
	i = 0;
	while (1)
	{
		aj2 = t_matrix_copy(aj);
		suurballe_reverse_path(&aj2, all_paths);
		t_matrix_init_identity(&collapser, aj2.m);
		split_paths_nodes(&aj2, all_paths, &collapser, start, end);
		if (!find_path(&aj2, &path, start, end))
			break;
		i++;
		collapse(&path, &collapser);
		*all_paths = t_matrix_add(all_paths, &path);
		remove_sym(all_paths);
		t_matrix_del(&aj2);
		t_matrix_del(&path);
	}
	t_matrix_del(&aj2);
	t_matrix_del(&collapser);
	return (i);
}
