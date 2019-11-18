/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:28:22 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 17:22:09 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void		t_matrix_t(t_matrix *a)
{
	int			i;
	int			j;
	t_matrix	b;

	t_matrix_init(&b, a->n, a->m);
	i = -1;
	while (++i < a->m)
	{
		j = -1;
		while (++j < a->n)
			b.data[j][i] = a->data[i][j];
	}
	t_matrix_del(a);
	ft_memcpy(a, &b, sizeof(t_matrix));
}

t_matrix	t_matrix_mul(t_matrix *a, t_matrix *b)
{
	t_matrix	r;
	int			i;
	int			j;
	int			k;

	t_matrix_init(&r, a->m, b->n);
	i = -1;
	while (++i < a->m)
	{
		j = -1;
		while (++j < b->n)
		{
			r.data[i][j] = 0;
			k = -1;
			while (++k < a->n)
			{
				r.data[i][j] += a->data[i][k] * b->data[k][j];
			}
		}
	}
	return (r);
}

void		print_path(int *path, int size, t_startend se)
{
	int i;

	(void)size;
	i = se.start;
	ft_putchar('\n');
	ft_putnbr(i);
	while (i != se.end)
	{
		ft_putstr("->");
		ft_putnbr(i = path[i]);
	}
	ft_putstr("\n");
}
