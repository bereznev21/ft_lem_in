/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_collapse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:58:26 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/17 22:51:39 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	t_collapse_add(t_collapse *c, int k)
{
	t_array_push(&c->a, &k);
}

void	t_collapse_do(t_collapse *c, int *path, int size, t_startend se)
{
	int k;
	int e;

	size = c->size;
	k = se.start;
	while (k != se.end)
	{
		if (path[k] >= size)
		{
			e = path[path[k]];
			path[k] = ((int*)c->a.data)[path[k] - c->size];
			path[path[k]] = e;
		}
		k = path[k];
	}
}

void	t_collapse_init(t_collapse *c, int size)
{
	c->size = size;
	t_array_init(&c->a, sizeof(int));
}
