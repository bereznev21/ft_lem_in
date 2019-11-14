#include "lem_in.h"

int		path_step(t_matrix *path, int k)
{
	int j;

	j = -1;
	while (++j < path->n)
		if (path->data[k][j])
			return (j);
	return (-1);
}
