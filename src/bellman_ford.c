#include "lem_in.h"
#include <limits.h>

static void relax_edges(t_matrix *aj, t_matrix *path, int *d)
{
	int i;
	int j;
	int k;
	int w;

	k = aj->n;
	while (k--)
	{
		i = -1;
		while (++i < aj->n)
		{
			j = -1;
			while (++j < aj->m)
			{
				if (aj->data[i][j] == DISJ)
					continue;
				w = aj->data[i][j];
				if (d[i] == DISJ)
					continue;
				if (d[j] > w + d[i])
				{
					d[j] = w + d[i];
					path->data[i][j] = 1;
				}
			}
		}
	}
}

int bellman_ford(t_matrix *aj, t_matrix *path, int start, int end)
{
	int i;
	int d[aj->n]; //distances from start node //todo: malloc

	for (i = 0; i < aj->n; i++)
		d[i] = DISJ;
	d[start] = 0;
	relax_edges(aj, path, d);
	// we don't check for the negative cycles;
	return (d[end] != DISJ);
}

int bf_shortest_path(t_matrix *aj, t_matrix *path, int stat, int end)
{
	int k;
	int i;
	t_matrix all_paths;

	t_matrix_init_zero(&all_paths, aj->m, aj->n);
	if (!bellman_ford(aj, &all_paths, stat, end))
		return 0;
	t_matrix_init_zero(path, aj->m, aj->n);
	k = end;
	while (k != stat)
	{
		i = -1;
		while (++i < aj->m)
		{
			if (all_paths.data[i][k])
			{
				path->data[i][k] = 1;
				k = i;
				break;
			}
		}
	}
	return (1);
}
