#include "lem_in.h"

void t_collapse_add(t_collapse *c, int k)
{
	t_matrix_duplicate_row(&c->m, k, c->m.m);
}

void t_collapse_do(t_collapse *c, t_matrix *aj)
{
	int i;
	t_matrix r;

	r = t_matrix_mul(aj, &c->m);
	t_matrix_del(aj);
	*aj = r;
	t_matrix_t(&c->m);
	r = t_matrix_mul(&c->m, aj);
	t_matrix_del(aj);
	*aj = r;
	i = -1;
	while (++i < aj->n)
		aj->data[i][i] = 0;
	t_matrix_del(&c->m);
}

void t_collapse_init(t_collapse *c, int size)
{
	t_matrix_init_identity(&c->m, size);
}
