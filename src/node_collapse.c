#include "lem_in.h"

void node_collapse_add(t_matrix *collapser, int k)
{
	t_matrix_duplicate_row(collapser, k, collapser->m);
}

void node_collapse(t_matrix *aj, t_matrix *collapser)
{
	int i;
	t_matrix r;

	r = t_matrix_mul(aj, collapser);
	t_matrix_del(aj);
	*aj = r;
	t_matrix_t(collapser);
	r = t_matrix_mul(collapser, aj);
	t_matrix_del(aj);
	*aj = r;
	i = -1;
	while (++i < aj->n)
		aj->data[i][i] = 0;
	t_matrix_del(collapser);
}

void node_collapse_init(t_matrix *collapser, int size)
{
	t_matrix_init_identity(collapser, size);
}

