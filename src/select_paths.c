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
	printf("%lu: ", n);
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
					  t_array *ret, unsigned long *intersection_mask, int depth)
{
	int i;
	unsigned long bpath;

//	i = -1;
//	while ((bpath = bpaths[++i]))
//		if (*set & 1 << i)
//			*intersection_mask |= bpath;
	i = -1;
	while ((bpath = bpaths[++i]))
	{
		if (*set & 1 << i)  //path is already in set
			continue;
		if (bpath & *intersection_mask) //path intersects
			continue;
		*set |= 1 << i;  //add path to set
		*intersection_mask |= bpath;
		if (!depth)
			t_array_push(ret, set); //we found set of n paths; add to result
		else
			iter_paths_recur(bpaths, set, ret, intersection_mask, depth - 1);
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
	iter_paths_recur(bpaths, &set, &ret, &intersection_mask, n - 1);
	return ret;
}

int **select_paths(int **paths, int size)
{
	int i;
	int j;
	unsigned long *bpaths;
	unsigned long bpath;
	t_array selected_paths;

	(void)selected_paths;
	(void)j;
	size = 4;
	print_paths(paths);
	bpaths = paths_to_bit_masks(paths, size);

	printf("bpath:\n");
	i = -1;
	while (++i < size)
		printf_bin_ulong(bpaths[i], 10);


	printf("non-intersecting paths:\n");
	selected_paths = select_n_paths(bpaths, 2);
//	return 0;
	i = -1;
	while (++i < selected_paths.count)
	{
		j = -1;
		bpath = *(unsigned long *)t_array_get(&selected_paths, i);
//		printf_bin_ulong(bpath, 10);
		while (bpaths[++j])
			if (bpath & 1 << j)
				print_path(paths[j]);
		printf("\n");
	}
	return paths;
}
