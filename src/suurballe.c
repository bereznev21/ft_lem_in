#include "lem_in.h"
#include <limits.h>

void t_matrix_duplicate_row(t_matrix *aj, int k);
void t_matrix_duplicate_col(t_matrix *aj, int k);
void t_matrix_duplicate_node(t_matrix *aj, int k);

int find_shortest_path(t_matrix *aj, t_matrix *path, int start, int end)
{
	int ret;

	t_matrix p;
	p = find_paths(aj, start, end);
	ret = ft_restore_patch(path, p, start, end);
	(void)ret;
	t_matrix_print(path);
	return ret; //store 1*n matrix into path; values are 0 and 1;
//	return (0);
}
/*
void reverse_path(t_matrix *path, int start, int end)
{
 t_matrix_t(path)
}
*/
void split_node(t_matrix *aj, int k, t_matrix *coll)
{
	int i;
	t_matrix_duplicate_node(aj, k);
	t_matrix_duplicate_row(coll, k);
	// k'th is IN; k+1'th us OUT
	for (i = 0; i < aj->n; i++)
	{
		aj->data[k][i] = DISJ; // remove all outs for input node
		aj->data[i][k + 1] = DISJ; //remove all inputs from output node
	}
	aj->data[k][k + 1] = 0; // link between split
}

void split_path_nodes(t_matrix *aj, t_matrix *path,
					  t_matrix *collapser, int start, int end)
{
	int i;

	i = -1;
	while (++i < aj->m)
		if (path->data[0][i] > 0 && i != start && i != end)
			split_node(aj, i, collapser);
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
	while (find_shortest_path(aj, &path, start, end))
	{
		i++;
		t_matrix_t(&path);
		split_path_nodes(aj, &path, &collapser, start, end);
		t_matrix_del(&path);
	}
	collapse(aj, &collapser);
	t_matrix_del(&collapser);
	return (i);
}
