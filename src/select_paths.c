#include <stdio.h>
#include "libft.h"
#include "lem_in.h"

int **find_paths_mock(t_matrix *aj, int start, int end)
{
	int **paths;

	(void)aj;
	(void)start;
	(void)end;
	paths = ft_memalloc(sizeof(int *) * 100);
	paths[0] = ft_memalloc(sizeof(int) * 100);
	paths[0][0] = 0;
	paths[0][1] = 1;
	paths[0][2] = 3;
	paths[0][3] = 5;
	paths[0][4] = -1;

	paths[1] = ft_memalloc(sizeof(int) * 100);
	paths[1][0] = 0;
	paths[1][1] = 1;
	paths[1][2] = 3;
	paths[1][3] = 2;
	paths[1][4] = 4;
	paths[1][5] = 5;
	paths[1][6] = -1;

	paths[2] = ft_memalloc(sizeof(int) * 100);
	paths[2][0] = 0;
	paths[2][1] = 2;
	paths[2][2] = 3;
	paths[2][3] = 5;
	paths[2][4] = -1;

	paths[3] = ft_memalloc(sizeof(int) * 100);
	paths[3][0] = 0;
	paths[3][1] = 2;
	paths[3][2] = 4;
	paths[3][3] = 5;
	paths[3][4] = -1;

	paths[4] = 0;
	return paths;
}

void print_paths(int **paths_arrays)
{
	int i;
	int j;

	i = -1;
	while (paths_arrays[++i])
	{
		j = -1;
		printf("path #%d: ", i);
		while (paths_arrays[i][++j] >= 0)
			printf("%d ", paths_arrays[i][j]);
		printf("\n");
	}
}

unsigned long *paths_to_bit_masks(int **paths_arrays, int size)
{
	int i;
	int j;
	unsigned long *bpaths;

	i = -1;
	bpaths = ft_memalloc(sizeof(unsigned long) * size);
	while (paths_arrays[++i])
	{
		j = -1;
		while (paths_arrays[i][++j] >= 0)
			bpaths[i] |= 1 << paths_arrays[i][j];
	}
	return (bpaths);
}

int **select_paths(int **paths, int size)
{
	int i;
	unsigned long *bpaths;

	size = 4;
	print_paths(paths);
	bpaths = paths_to_bit_masks(paths, size);
	i = -1;
	while (++i < size)
		printf("%lu\n", bpaths[i]);
	return paths;
}
