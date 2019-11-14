/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_collapse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:58:26 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/12 17:58:27 by ksticks          ###   ########.fr       */
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

	k = se.start;
	while(k != se.end)
	{
		if (path[k] >= size)
		{
			e = path[k];
			while(e >= size)
				e = path[e];
			path[k] = e;
		}
		k = path[k];
	}
}

void	t_collapse_init(t_collapse *c, int size)
{
	c->size = size;
	t_array_init(&c->a, sizeof(int));
}
