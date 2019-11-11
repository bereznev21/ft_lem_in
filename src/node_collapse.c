#include "lem_in.h"

void t_collapse_add(t_collapse *c, int k)
{
	t_array_push(&c->a, &k);
}

static void t_collapse_new(t_collapse *c, t_matrix *paths)
{
	int i;
	int j;
	int k;

	i = c->a.count;
	while (--i >= 0)
	{
		k = *(int *) t_array_get(&c->a, i);
		j = paths->m;
		while(--j >= 0)
		{
			paths->data[j][k] += paths->data[j][i + c->size];
			paths->data[k][j] += paths->data[i + c->size][j];
		}
		paths->m--;
		paths->n--;
	}
}

void t_collapse_do(t_collapse *c, t_matrix *paths)
{
	t_collapse_new(c, paths);
}

void t_collapse_init(t_collapse *c, int size)
{
	c->size = size;
	t_array_init(&c->a, sizeof(int));
}
