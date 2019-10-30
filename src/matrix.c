#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"


void t_matrix_init(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	mat->m = m;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = DISJ;
	}
}

void t_matrix_init_zero(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	mat->m = m;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = 0;
	}
}


void t_matrix_init_identity(t_matrix *mat, int n)
{
	int i;

	mat->m = n;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		ft_bzero(mat->data[i], mat->n * sizeof(int));
		mat->data[i][i] = 1;
	}
}

void t_matrix_print_no_headers(t_matrix *m)
{
	int i;
	int j;

	i = -1;
	while (++i < m->m)
	{
		j = -1;
		while (++j < m->n)
			printf("% 3d ", m->data[i][j]);
		printf("\n");
	}
	printf("\n");
}

void t_matrix_print(t_matrix *m)
{
	int i;
	int j;

	printf("  |");
	j = -1;
	while (++j < m->n)
		printf("% 2d ", j);
	printf("\n");
	printf("--+");
	j = -1;
	while (++j < m->n)
		printf("---");
	printf("\n");
	i = -1;
	while (++i < m->m)
	{
		printf("% 2d|", i);
		j = -1;
		while (++j < m->n)
			m->data[i][j] != DISJ ? printf("% 2d ", m->data[i][j]) : printf(" . ");
		printf("\n");
	}
	printf("\n");
}

void t_matrix_set(t_matrix *m, int i, int j, int v)
{
	m->data[i][j] = v;
	m->data[j][i] = v;
}

void t_matrix_fill(t_matrix *m)
{
	t_matrix_set(m, 0, 1, 1);
	t_matrix_set(m, 0, 2, 1);
	t_matrix_set(m, 1, 4, 1);
	t_matrix_set(m, 2, 3, 1);
	t_matrix_set(m, 2, 4, 1);
	t_matrix_set(m, 3, 5, 1);
	t_matrix_set(m, 4, 5, 1);
}

void t_matrix_t(t_matrix *a)
{
	int i;
	int j;
	t_matrix b;

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

t_matrix t_matrix_mul(t_matrix *a, t_matrix *b)
{
	t_matrix r;
	int i;
	int j;
	int k;

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

void t_matrix_del(t_matrix *m)
{
	int i;

	i = 0;
	while (i < m->m)
		free(m->data[i++]);
	free(m->data);
}

void lem_in_test()
{
	t_matrix map;
	t_matrix flow;

	t_matrix_init(&map, 6, 6);

	t_matrix_fill(&map);
	t_matrix_print_no_headers(&map);
	flow = push_relabel(&map, 0, 5);
	t_matrix_print_no_headers(&flow);
}
