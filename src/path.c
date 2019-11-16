#include "lem_in.h"

void		print_path(int *path, int size, t_startend se)
{
	int i;

	(void)size;
//	for (i = 0; i < size; ++i)
//		if (path[i] == DISJ)
//			printf(". ");
//		else
//			printf("%d ", path[i]);
//	printf("\n");
	i = se.start;
	printf("%d", i);
	while (i != se.end)
	{
		printf("->%d", (i = path[i]));
	}
	printf("\n");
	printf("\n");
}

void		print_paths(t_paths pp)
{
	int i;

	i = -1;
	while(pp.paths[++i])
		print_path(pp.paths[i], pp.size, pp.se);
}
