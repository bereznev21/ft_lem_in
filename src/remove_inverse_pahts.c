/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_inverse_pahts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:15 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/16 17:42:46 by rpoetess         ###   ########.fr       */
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

static void	merge_paths(t_paths pp, int i, int j, int n)
{
	int	*p1;
	int	*p2;
	int	k;

	p1 = malloc(sizeof(int) * pp.size);
	p2 = malloc(sizeof(int) * pp.size);
	k = -1;
	while (++k < pp.size)
	{
		p1[k] = DISJ;
		p2[k] = DISJ;
	}
	k = pp.se.start;
	while (k != n)
		k = (p1[k] = pp.paths[i][k]);
	while (k != pp.se.end)
		k = (p1[k] = pp.paths[j][k]);
	k = pp.se.start;
	while (k != pp.paths[i][n])
		k = (p2[k] = pp.paths[j][k]);
	while (k != pp.se.end)
		k = (p2[k] = pp.paths[i][k]);
	free(pp.paths[i]);
	free(pp.paths[j]);
	pp.paths[i] = p1;
	pp.paths[j] = p2;
}

void		remove_sym(t_paths pp)
{
	int i;
	int j;
	int k;

	//printf("remove sym\n");
	i = -1;
	//while (pp.paths[++i])
	//	print_path(pp.paths[i], pp.size, pp.se);
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
	//printf("remove sym done\n");
	i = -1;
	//while (pp.paths[++i])
	//	print_path(pp.paths[i], pp.size, pp.se);
}
