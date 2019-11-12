/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:17:25 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 15:48:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_matrix	t_matrix_add(t_matrix *a, t_matrix *b)
{
	int			i;
	int			j;
	t_matrix	r;

	t_matrix_init(&r, a->m, a->n);
	i = -1;
	while (++i < a->m)
	{
		j = -1;
		while (++j < a->n)
		{
			r.data[i][j] = a->data[i][j] + b->data[i][j];
		}
	}
	return (r);
}

void		t_matrix_set(t_matrix *m, int i, int j, int v)
{
	m->data[i][j] = v;
	m->data[j][i] = v;
}

void		t_matrix_duplicate_row(t_matrix *aj, int k, int m)
{
	int i;
	int *src_row;

	if (aj->m + 1 > aj->m_alloc)
	{
		i = aj->m_alloc;
		aj->m_alloc = round_up(aj->m + 1);
		aj->data = ft_realloc(aj->data,
						sizeof(int *) * aj->m,
						sizeof(int *) * aj->m_alloc);
		while (i < aj->m_alloc)
			aj->data[i++] = malloc(sizeof(int) * aj->n_alloc);
	}
	src_row = aj->data[k];
	ft_memmove(&aj->data[m + 1], &aj->data[m], sizeof(int *) * (aj->m - m));
	ft_memcpy(aj->data[m], src_row, sizeof(int) * aj->n);
	aj->m++;
}

void		t_matrix_duplicate_col(t_matrix *aj, int k, int m)
{
	int i;
	int v;

	if (aj->n + 1 > aj->n_alloc)
	{
		aj->n_alloc = round_up(aj->n + 1);
		i = -1;
		while (++i < aj->m_alloc)
			aj->data[i] = ft_realloc(aj->data[i],
							sizeof(int) * aj->n,
							sizeof(int) * aj->n_alloc);
	}
	i = -1;
	while (++i < aj->m)
	{
		v = aj->data[i][k];
		ft_memmove(&aj->data[i][m + 1], &aj->data[i][m],
					sizeof(int) * (aj->n - m));
		aj->data[i][m] = v;
	}
	aj->n++;
}

void		t_matrix_del(t_matrix *matrix)
{
	int i;

	i = -1;
	while (++i < matrix->m_alloc)
		free(matrix->data[i]);
	free(matrix->data);
}
