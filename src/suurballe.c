/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 14:13:38 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	suurballe_reverse_path(t_matrix *aj, int **all_paths, t_startend se)
{
	int k;
	int prev;
	int *path;

	while((path = *all_paths++))
	{
		k = se.start;
		while(k != se.end)
		{
			prev = k;
			k = path[prev];
			aj->data[k][prev] = -aj->data[prev][k];
			aj->data[prev][k] = DISJ;
		}
	}
}

void	remove_sym(int **paths)
{
/*	int i;
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
	}*/
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

void	split_paths_nodes(t_matrix *aj, int **all_paths,
							t_collapse *c, t_startend se)
{
	int k_prev;
	int k_next;
	int k;
	int* path;

	while((path = *all_paths++))
	{
		k_prev = se.start;
		k = path[k_prev];
		while(k != se.end){
			k_next = path[k];
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

int		**suurballe_next(t_matrix aj, int **all_paths, t_startend se)
{
	t_collapse	c;
	int	*path;
	int n;
	//all_paths: null-terminated array of paths;

	aj = t_matrix_copy(&aj);
	suurballe_reverse_path(&aj, all_paths, se);
	t_collapse_init(&c, aj.m);
	split_paths_nodes(&aj, all_paths, &c, se);
	if (!(path = find_path(&aj, 0, se)))//todo: find_path should free memory when path not found
	{
		t_matrix_del(&aj);
		t_array_del(&c.a);
		return (0);
	}
	t_collapse_do(&c, path, aj.n, se);
	t_array_del(&c.a);
	n = ft_len((void**)all_paths);
	all_paths = ft_realloc(all_paths, n + 1, n + 2); //todo: use t_array here?
	all_paths[n + 1] = 0;
	all_paths[n] = path;
	remove_sym(all_paths);
	t_matrix_del(&aj);
	return (all_paths);
}
