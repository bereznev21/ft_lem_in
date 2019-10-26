#include <stdio.h>
#include "lem_in.h"
#include "libft/includes/libft.h"

void t_matrix_duplicate_row(t_matrix *aj, int k)
{
	aj->data = ft_realloc(aj->data,
						  sizeof(int *) * aj->m,
						  sizeof(int *) * (aj->m + 1));

	ft_memmove(&aj->data[k + 1], &aj->data[k], sizeof(int *) * (aj->m - k));
	aj->data[k] = ft_memdup(aj->data[k], sizeof(int) * aj->n);
	aj->m++;
}

void t_matrix_duplicate_col(t_matrix *aj, int k)
{
	int i;

	i = -1;
	while (++i < aj->m)
	{
		aj->data[i] = ft_realloc(aj->data[i],
								 sizeof(int) * aj->n,
								 sizeof(int) * (aj->n + 1));
		ft_memmove(&aj->data[i][k + 1], &aj->data[i][k],
				   sizeof(int) * (aj->n - k));
	}
	aj->n++;
}

void t_matrix_collapse_col(t_matrix *aj, int k)
{
	int i;

	aj->n--;
	i = -1;
	while (++i < aj->m)
	{
		ft_memmove(&aj->data[i][k], &aj->data[i][k + 1],
				   sizeof(int) * (aj->n - k));
	}
}

void t_matrix_duplicate_node(t_matrix *aj, int k)
{
	t_matrix_duplicate_row(aj, k);
	t_matrix_duplicate_col(aj, k);
}

int t_matrix_node_outs_cnt(t_matrix *aj, int i)
{
	int j;
	int ret;

	ret = 0;
	j = i - 1;
	while (++j < aj->n)
		ret += aj->data[i][j] > 0;
	return ret;
}

void wipe_cross(t_matrix *aj, int k)
{
	int i;

	i = -1;
	while (++i < aj->n)
	{
		aj->data[i][k] = 0;
		aj->data[k][i] = 0;
	}
}

void split_node(t_matrix *aj, int k, int cnt, t_matrix *r)
{
	int i;
	int j;

	i = k - 1;
	while (++i < k + cnt - 1)
	{
		j = 0;
		while (!aj->data[i][j])
			j++;
		t_matrix_duplicate_node(aj, i);
		t_matrix_duplicate_row(r, i);
		if (j > i)
			j++;
		wipe_cross(aj, i);
		t_matrix_set(aj, i, j, 1);
		t_matrix_set(aj, i + 1, j, 0);
	}
	j = k - 1;
	while (++j < i)
		aj->data[j][j + 1] = 1;
	aj->data[j][k] = 1;
}

int node_conn_cnt(t_matrix *aj, int k)
{
	int i;
	int r;

	r = 0;
	i = -1;
	while (++i < aj->m)
		r += (aj->data[i][k] > 0);
	return (r);
}


t_matrix expand_junctions(t_matrix *aj)
{
	t_matrix r;
	int i;
	int cnt;

	t_matrix_init_identity(&r, aj->n);
	// after the splitting rT * aj * r reverses the expansion
	for (i = 0; i < aj->n; ++i)
	{
		cnt = node_conn_cnt(aj, i);
		if (cnt >= 4)
		{
			split_node(aj, i, cnt, &r);
			i += cnt - 1;
		}
	}
	return (r);
}