/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 19:45:56 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	suurballe_reverse_path(t_matrix *aj, t_paths pp)
{
	int k;
	int prev;
	int *path;
	int i;

	i = -1;
	while ((path = pp.paths[++i]))
	{
		k = pp.se.start;
		while (k != pp.se.end)
		{
			prev = k;
			k = path[prev];
			aj->data[k][prev] = -aj->data[prev][k];
			aj->data[prev][k] = DISJ;
		}
	}
}

void		split_path_node(t_matrix *aj, int k, int prev, int next)
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

void		split_paths_nodes(t_matrix *aj, t_paths pp, t_collapse *c)
{
	int k_prev;
	int k_next;
	int k;
	int	*path;
	int i;

	i = -1;
	while ((path = pp.paths[++i]))
	{
		k_prev = pp.se.start;
		k = path[k_prev];
		while (k != pp.se.end)
		{
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

int			suurballe_next(t_matrix aj, t_paths *pp)
{
	t_collapse	c;
	int			*path;
	int			size;

	size = aj.n;
	aj = t_matrix_copy(&aj);
	suurballe_reverse_path(&aj, *pp);
	t_collapse_init(&c, aj.m);
	split_paths_nodes(&aj, *pp, &c);
	if (!(path = find_path(&aj, pp->se)))
	{
		t_matrix_del(&aj);
		t_array_del(&c.a);
		return (0);
	}
	t_collapse_do(&c, path, size, pp->se);
	t_array_del(&c.a);
	pp->paths[ft_len((void**)pp->paths)] = path;
	remove_sym(*pp);
	t_matrix_del(&aj);
	return (1);
}
