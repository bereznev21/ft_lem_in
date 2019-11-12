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

void	t_collapse_do(t_collapse *c, t_matrix *paths)
{
	int i;
	int j;
	int k;

	i = c->a.count;
	while (--i >= 0)
	{
		k = *(int *)t_array_get(&c->a, i);
		j = paths->m;
		while (--j >= 0)
		{
			paths->data[j][k] += paths->data[j][i + c->size];
			paths->data[k][j] += paths->data[i + c->size][j];
		}
		paths->m--;
		paths->n--;
	}
}

void	t_collapse_init(t_collapse *c, int size)
{
	c->size = size;
	t_array_init(&c->a, sizeof(int));
}
