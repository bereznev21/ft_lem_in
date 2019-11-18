/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_inverse_pahts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:15 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/17 22:38:12 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		remove_sym_old(t_matrix *path)
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

static void	merger(t_paths pp, int i, int j, t_merger m)
{
	int k;

	k = pp.se.start;
	while (k != m.n)
	{
		m.p1[k] = pp.paths[i][k];
		k = m.p1[k];
	}
	while (k != pp.se.end)
	{
		m.p1[k] = pp.paths[j][k];
		k = m.p1[k];
	}
	k = pp.se.start;
	while (k != pp.paths[i][m.n])
	{
		m.p2[k] = pp.paths[j][k];
		k = m.p2[k];
	}
	while (k != pp.se.end)
	{
		m.p2[k] = pp.paths[i][k];
		k = m.p2[k];
	}
}

static void	merge_paths(t_paths pp, int i, int j, int n)
{
	int			k;
	t_merger	m;

	m.p1 = malloc(sizeof(int) * pp.size);
	m.p2 = malloc(sizeof(int) * pp.size);
	m.n = n;
	k = -1;
	while (++k < pp.size)
	{
		m.p1[k] = DISJ;
		m.p2[k] = DISJ;
	}
	merger(pp, i, j, m);
	free(pp.paths[i]);
	free(pp.paths[j]);
	pp.paths[i] = m.p1;
	pp.paths[j] = m.p2;
}

void		remove_sym(t_paths pp)
{
	int i;
	int j;
	int k;

	i = -1;
	i = -1;
	while (pp.paths[++i])
	{
		k = pp.se.start;
		while ((k = pp.paths[i][k]) != pp.se.end)
		{
			j = i;
			while (pp.paths[++j])
				if (k == pp.paths[j][pp.paths[i][k]])
					merge_paths(pp, i, j, k);
		}
	}
	i = -1;
}
