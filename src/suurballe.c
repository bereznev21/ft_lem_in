#include "lem_in.h"
#include <limits.h>
#include <stdio.h>

void t_matrix_duplicate_row(t_matrix *aj, int k);
void t_matrix_duplicate_col(t_matrix *aj, int k);
void t_matrix_duplicate_node(t_matrix *aj, int k);


int find_shortest_path(t_matrix *aj, t_matrix *path, int start, int end)
{
	t_matrix paths_map;

	if (find_paths(aj, &paths_map, start, end) == 1)
		if (ft_restore_patch(path, paths_map, start, end) == 1)
			return (1);
	return (0);
}

void split_node(t_matrix *aj, int k)
{
	int i;

	t_matrix_duplicate_node(aj, k);
	// k'th is IN; k+1'th us OUT
	for (i = 0; i < aj->n; i++)
	{
		aj->data[k][i] = DISJ; // remove all outs for input node
		aj->data[i][k + 1] = DISJ; //remove all inputs from output node
	}
	aj->data[k][k + 1] = 0; // link between split
}

void split_path_nodes(t_matrix *aj, t_matrix *path,
					  t_matrix *collapser, int *start, int *end)
{
	int i;
	t_matrix path_diag;

//	printf("split!\n");
	path_diag = t_matrix_copy(path);
	t_matrix_t(&path_diag);
	path_diag = t_matrix_mul(&path_diag, path);
//	t_matrix_print(&path_diag);
//	fflush(stdout);
	i = -1;
	while (++i < path_diag.n)
		if (path_diag.data[i][i] == 1 && i != *start && i != *end)
		{
			if (*start > i)
				(*start)++;
			if (*end > i)
				(*end)++;
			t_matrix_duplicate_node(&path_diag, i);
			t_matrix_duplicate_row(collapser, i);
			split_node(aj, i);
			i++;
		}
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

void suurballe_reverse_path(t_matrix *aj, t_matrix *path)
{
	int i;
	int j;

	i = -1;
	while (++i < aj->m)
	{
		j = -1;
		while (++j < aj->n)
		{
			if (path->data[i][j])
			{
				aj->data[j][i] = -aj->data[i][j];
				aj->data[i][j] = DISJ;
			}
		}
	}
}

void remove_sym(t_matrix *path)
{
	int i;
	int j;

	i = -1;
	while (++i < path->m)
	{
		j = i - 1;
		while (++j < path->n)
		{
			if (path->data[i][j] == 1 && path->data[j][i] == 1)
			{
				path->data[i][j] = 0;
				path->data[j][i] = 0;
			}
		}
	}
}

int suurballe(t_matrix *aj, int start, int end)
{
	t_matrix collapser;
	t_matrix path;
	t_matrix all_paths;
	t_matrix aj2;
	int i;

	t_matrix_init_zero(&all_paths, aj->m, aj->n);
	i = 0;
	while (1)
	{
		suurballe_reverse_path(aj, &all_paths);
		t_matrix_init_identity(&collapser, aj->m);
		aj2 = t_matrix_copy(aj);
		split_path_nodes(&aj2, &all_paths, &collapser, &start, &end);
		if (!find_shortest_path(&aj2, &path, start, end))
			break;
		i++;
		collapse(&path, &collapser);
		all_paths = t_matrix_add(&all_paths, &path);
		remove_sym(&all_paths);

		t_matrix_del(&aj2);
		t_matrix_del(&collapser);
		t_matrix_del(&path);
	}
	t_matrix_del(&collapser);
	t_matrix_print(&all_paths);
	return (i);
}
