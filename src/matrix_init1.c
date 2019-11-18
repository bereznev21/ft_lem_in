/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:14:58 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/17 23:15:01 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		t_matrix_init_identity(t_matrix *mat, int n)
{
	int i;

	t_matrix_init_zero(mat, n, n);
	i = -1;
	while (++i < mat->m)
		mat->data[i][i] = 1;
}

t_matrix	t_matrix_copy(t_matrix *m)
{
	int			i;
	int			j;
	t_matrix	ret;

	t_matrix_alloc(&ret, m->m, m->n);
	i = -1;
	while (++i < ret.m)
	{
		j = -1;
		while (++j < ret.n)
			ret.data[i][j] = m->data[i][j];
	}
	return (ret);
}
