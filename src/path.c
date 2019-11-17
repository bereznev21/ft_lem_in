#include "libft.h"
#include "lem_in.h"

void		t_paths_init(t_paths *pp, t_startend se, int size)
{
	pp->paths = ft_memalloc(sizeof(int*) * 256);
	pp->se = se;
	pp->size = size;
	pp->paths_rev = 0;
}

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

void		t_paths_init_rev(t_paths *pp)
{
	int i;
	int k;

	if (pp->paths_rev)
		free(pp->paths_rev);
	pp->paths_rev = malloc(sizeof(int *) * ft_len((void **)pp->paths));
	i = -1;
	while(pp->paths[++i])
	{
		pp->paths_rev[i] = malloc(sizeof(int) * pp->size);
		k = pp->se.start;
		while(k != pp->se.end)
		{
			pp->paths_rev[i][pp->paths[i][k]] = k;
			k = pp->paths[i][k];
		}
	}
}
