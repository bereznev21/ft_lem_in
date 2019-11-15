/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_inverse_pahts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:36:15 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/15 19:05:56 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void remove_sym_old(t_matrix *path)
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

static void merge_paths(int **path1, int **path2, t_startend se, int n,
						int size)
{
	int *p1;
	int *p2;
	int k;

	p1 = malloc(sizeof(int) * size);
	p2 = malloc(sizeof(int) * size);
	k = -1;
	while (++k < size)
	{
		p1[k] = DISJ;
		p2[k] = DISJ;
	}
	k = se.start;
	while (k != n)
		k = (p1[k] = (*path1)[k]);
	while (k != se.end)
		k = (p1[k] = (*path2)[k]);
	k = se.start;
	while (k != (*path1)[n])
		k = (p2[k] = (*path2)[k]);
	while (k != se.end)
		k = (p2[k] = (*path1)[k]);
	free(*path1);
	free(*path2);
	*path1 = p1;
	*path2 = p2;
}

void remove_sym(int **paths, int size, t_startend se)
{
	int i;
	int j;
	int k;

	i = -1;
	while (paths[++i])
	{
		k = se.start;
		while((k = paths[i][k]) != se.end)
		{
			j = i;
			while(paths[++j])
				if (k == paths[j][paths[i][k]])
					merge_paths(&paths[i], &paths[j], se, k, size);
		}
	}
}
