/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:42:59 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 17:00:49 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int			round_up(int a)
{
	return (((a - 1) / MAT_ALLOC_STEP + 1) * MAT_ALLOC_STEP);
}
void		t_matrix_alloc(t_matrix *mat, int m, int n)
{
	int i;

	mat->m = m;
	mat->n = n;
	mat->m_alloc = round_up(m);
	mat->n_alloc = round_up(n);
	mat->data = malloc(sizeof(int *) * mat->m_alloc);
	i = -1;
	while (++i < mat->m_alloc)
		mat->data[i] = malloc(sizeof(int) * mat->n_alloc);
}

void		t_matrix_fill(t_matrix *mat, int v)
{
	int i;
	int j;

	i = -1;
	while (++i < mat->m)
	{
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = v;
	}
}

void		t_matrix_init(t_matrix *mat, int m, int n)
{
	t_matrix_alloc(mat, m, n);
	t_matrix_fill(mat, DISJ);
}

void		t_matrix_init_zero(t_matrix *mat, int m, int n)
{
	t_matrix_alloc(mat, m, n);
	t_matrix_fill(mat, 0);
}

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
