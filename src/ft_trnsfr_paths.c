#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void	t_matrix_init_minus(t_matrix *mat, int m, int n)
{
	int i;
	int	j;

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
void	ft_put_end(int *roads, int end)
{
	int n;

	n = 0;
	while ((roads)[n] > -1)
		n++;
	(roads)[n] = end;
}

void	ft_src_roads1(t_matrix *res, t_matrix *map, int frst_room, int num_room)
{
	int	j;
	int	room;

	room = frst_room;
	j = 0;
	//while (1)
	{
		while (j < map->m)
		{
			if (map->data[room][j] == 1)
			{
				ft_put_end(res->data[num_room], j);
				ft_src_roads1(res, map, j, num_room);
				//room = j;
			}
			j++;
		}
		//printf("%d:%d ", room, map->data[room][j]);
	}
//	printf("\n");
}

t_matrix	ft_trnsfr_paths(t_matrix paths_map, int start)
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
		if (paths.data[start][j] == 1)
		{
			paths.data[n][0] = j;
			n++;
		}
	j = -1;
	while (++j < num_paths)
		ft_src_roads1(&paths, &paths_map, paths.data[j][0], j);
	t_matrix_print(&paths);
	return (paths);
}
