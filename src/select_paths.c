#include <stdio.h>
#include "libft.h"
#include "lem_in.h"

int **find_paths(t_matrix *aj, int start, int end)
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

int **select_paths(int **paths)
{
	int i;
	int j;

	i = -1;
	while (paths[++i])
	{
		j = -1;
		printf("path #%d: ", i);
		while (paths[i][++j] >= 0)
			printf("%d ", paths[i][j]);
		printf("\n");
	}
	return paths;
}
