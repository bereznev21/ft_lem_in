#include <stdio.h>
#include <libft.h>
#include <lem_in.h>

int path_step(t_matrix *path, int k);

void print_paths(t_matrix *paths, int start, int end)
{
	int j;
	int k;
	int size;

	size = paths->m;
	for (j = 0; j < size; ++j)
	{
		if (!paths->data[start][j])
			continue;
		printf("%d->", start);
		k = j;
		printf("%d->", k);
		while (k != end)
		{
			k = path_step(paths, k);
			printf("%d->", k);
		}
		printf("\n");
	}
	fflush(stdout);
}

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


void		t_matrix_print_no_headers(t_matrix *m)
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

void		t_matrix_print(t_matrix *m)
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
			m->data[i][j] != DISJ ? printf("% 2d ", m->data[i][j]) : printf(
					" . ");
		printf("\n");
	}
	printf("\n");
	fflush(stdout);
}
