/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:42:59 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/17 23:14:38 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
