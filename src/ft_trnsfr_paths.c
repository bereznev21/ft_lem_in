#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void t_matrix_init_minus(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	mat->m = m;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	j = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		while (++j < n)
			mat->data[i][j] = -1;
		j = -1;
	}
}


/*
void	ft_src_roads(t_matrix *ans, t_matrix *map, int k)
{
	int i;
	int j;

	i = k;
	j = 0;

	while (1)
	{
		while (ans->data[i][j] != 1 && j < ans->n)
			j++;
		if (ans->data[i][j] == 1)
			ft_put_end(map, k, j);
		i = j;
		j = 0;
	}
}
*/
void ft_put_end(int *roads, int end)
{
	int n;

	n = 0;
	while ((roads)[n] > -1)
		n++;
	(roads)[n] = end;
}

void ft_src_roads1(t_matrix *res, t_matrix *map, int frst_room, int num_room)
{
	int j;
	int room;

	room = frst_room;
	j = 0;
	(void)frst_room;
	(void)num_room;
	(void)res;
	//while (1)
	{
		while (j < map->m)
		{
			if (map->data[room][j] == 1)
			{
				ft_put_end(res->data[num_room], j);
				ft_src_roads1(res, map, j, num_room);
				room = j;
			}
			j++;
		}
	}
}

/*
t_matrix	ft_trnsfr_paths(t_matrix paths_map, int start, int end)
{
	int			j;
	int			n;
	int			num_paths;
	t_matrix	paths;

	n = 0;
	j = -1;
	num_paths = 0;
	while (++j < paths_map.m)
		if (paths_map.data[start][j] == 1)
			num_paths++;
	j = -1;
	t_matrix_init_minus(&paths, num_paths, paths_map.n);
	while (++j < paths_map.m)
	{
		if (paths_map.data[start][j] == 1)
		{
			//printf("%d\n", j);
			paths.data[n][0] = j;
			n++;
		}
	}
	j = -1;
	while (++j < num_paths)
	//	printf("%d\n", paths.data[j][0]);
		ft_src_roads1(&paths, &paths_map, paths.data[j][0], j);
	t_matrix_print(&paths);
	return (paths);
}
*/

void matrix_to_bits_recur(t_matrix *m, int i, int end, unsigned long *path, t_array *a)
{
	int j;

	for (j = 0; j < m->n; ++j)
	{
		if (m->data[i][j] == 1)
		{
			if (j == end)
			{
				t_array_push(a, path);
				return;
			}
			*path |= 1 << j;
			matrix_to_bits_recur(m, j, end, path, a);
			*path ^= 1 << j;
		}
	}
}

void printf_bin_ulong(unsigned long n, int k);


t_array path_matrix_to_bit_masks(t_matrix *paths_map, int start, int end)
{
	t_array a;
	unsigned long path;

	(void)paths_map;
	(void)start;
	(void)end;
	t_array_init(&a, sizeof(unsigned long));
	path = 0;
	matrix_to_bits_recur(paths_map, start, end, &path, &a);

	int i;
	for (i = 0; i < a.count; ++i)
		printf_bin_ulong(*(unsigned long *)t_array_get(&a, i), 10);
	return (a);
}
