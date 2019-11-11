/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:42:59 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 15:43:02 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		round_up(int a)
{
	return (((a - 1) / MAT_ALLOC_STEP + 1) * MAT_ALLOC_STEP);
}

void	t_matrix_init(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	mat->m = m;
	mat->n = n;
	mat->m_alloc = round_up(m);
	mat->n_alloc = round_up(n);
	mat->data = malloc(sizeof(int *) * mat->m_alloc);
	i = -1;
	while (++i < mat->m_alloc)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n_alloc);
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = DISJ;
	}
}

void	t_matrix_init_zero(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	t_matrix_init(mat, m, n);
	i = -1;
	while (++i < mat->m)
	{
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = 0;
	}
}

void	t_matrix_init_identity(t_matrix *mat, int n)
{
	int i;

	t_matrix_init_zero(mat, n, n);
	i = -1;
	while (++i < mat->m)
		mat->data[i][i] = 1;
}
