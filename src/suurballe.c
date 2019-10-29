#include "lem_in.h"

int find_shortest_path(t_matrix *aj, int start, int end)
{
	return 0;
}

void reverse_path(t_matrix *path)
{

}

void write_path_to_aj(t_matrix **aj)
{

}

void split_path_nodes(t_matrix *a, t_matrix *collapser)
{

}

void collapse(t_matrix *aj, t_matrix *collapser)
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
}


int suurballe(t_matrix *aj, int start, int end)
{
	t_matrix collapser;
	t_matrix path;
	int i;

	t_matrix_init_identity(&collapser, aj->m);
	i = 0;
	while (find_shortest_path(aj, start, end))
	{
		i++;
		reverse_path(aj);
		split_path_nodes(aj, &collapser);
	}
	collapse(aj, &collapser);
	return (i);
}
