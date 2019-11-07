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
	paths[0][0] = 1;
	paths[0][1] = 3;
	paths[0][2] = -1;

	paths[1] = ft_memalloc(sizeof(int) * 100);
	paths[1][0] = 1;
	paths[1][1] = 3;
	paths[1][2] = 2;
	paths[1][3] = 4;
	paths[1][4] = -1;

	paths[2] = ft_memalloc(sizeof(int) * 100);
	paths[2][0] = 2;
	paths[2][1] = 3;
	paths[2][2] = -1;

	paths[3] = ft_memalloc(sizeof(int) * 100);
	paths[3][0] = 2;
	paths[3][1] = 4;
	paths[3][2] = -1;

	paths[4] = 0;
	return paths;
}

void printf_bin_ulong(unsigned long n, int k)
{
	printf("%6lu:\t", n);
	while (k--)
	{
		printf(n & 1 ? "1" : "0");
		n >>= 1;
	}
	printf("\n");
}

void print_path(int *path_array)
{
	int j;

	j = -1;
	printf("[");
	while (path_array[++j] >= 0)
	{
		if (j)
			printf("-");
		printf("%d", path_array[j]);
	}
	printf("] ");
}

void print_paths(int **paths_arrays)
{
	int i;

	i = -1;
	while (paths_arrays[++i])
	{
		printf("#%d ", i);
		print_path(paths_arrays[i]);
		printf("\n");
	}
}

unsigned long *paths_to_bit_masks(int **paths_arrays, int size)
{
	int i;
	int j;
	unsigned long *bpaths;

	i = -1;
	bpaths = ft_memalloc(sizeof(unsigned long) * (size + 1));
	while (paths_arrays[++i])
	{
		j = -1;
		while (paths_arrays[i][++j] >= 0)
			bpaths[i] |= 1 << paths_arrays[i][j];
	}
	paths_arrays[i] = 0;
	return (bpaths);
}

void iter_paths_recur(const unsigned long *bpaths, unsigned long *set,
					  t_array *ret, unsigned long *intersection_mask, int depth,
					  unsigned int offset)
{
	int i;
	unsigned long bpath;

	i = (int)offset - 1;
	while ((bpath = bpaths[++i]))
	{
		if (*set & 1 << i)  //path is already in set
			continue;
		if (bpath & *intersection_mask) //path intersects with current set
			continue;
		*set |= 1 << i;  //add path to set
		*intersection_mask |= bpath;
		if (!depth)
			t_array_push(ret, set); //we found set of n paths; add to result
		else
			iter_paths_recur(bpaths, set, ret, intersection_mask, depth - 1,
							 offset + i + 1);
		*intersection_mask ^= bpath;
		*set ^= 1 << i;  //remove path from set
	}
}

t_array select_n_paths(unsigned long *bpaths, int n)
{
	t_array ret;
	unsigned long set;
	unsigned long intersection_mask;

	t_array_init(&ret, sizeof(set));
	set = 0;
	intersection_mask = 0;
	iter_paths_recur(bpaths, &set, &ret, &intersection_mask, n - 1, 0);
	return ret;
}

ULONG select_paths(t_array *arr)
{
	int i;
	int j;
	ULONG paths_mask;
	ULONG *bpaths;
	t_array path_sets;

	(void)path_sets;
	(void)j;

	paths_mask = 0;
	t_array_push(arr, &paths_mask); //terminate
	bpaths = arr->data;
	path_sets = select_n_paths(bpaths, 2);
	i = -1;
	printf("non-intersecting paths:\n");
	while (++i < path_sets.count)
	{
		j = -1;
		paths_mask = *(ULONG *)t_array_get(&path_sets, i);
		while (bpaths[++j])
			if (paths_mask & 1 << j)
				printf_bin_ulong(bpaths[j], 10);
//				printf("%lu ", bpaths[j]);
		printf("\n");
	}
	return 0;
}
