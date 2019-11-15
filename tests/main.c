#include "lem_in.h"

static void print_path(int *path, int size, t_startend se)
{
	int i;

	for (i = 0; i < size; ++i)
		if (path[i] == DISJ)
			printf(". ");
		else
			printf("%d ", path[i]);
	printf("\n");
	i = se.start;
	printf("%d", i);
	while(i != se.end)
	{
		printf("->%d", (i = path[i]));
	}
	printf("\n");
}

void test_remove_sym()
{
	int **paths;
	int size = 8;
	int i;
	t_startend se;
	int *p1;

	se = (t_startend){0, 7};
	paths = malloc(sizeof(int *) * 3);
	paths[0] = malloc(sizeof(int) * size);
	paths[1] = malloc(sizeof(int) * size);
	paths[2] = 0;
	p1 = paths[0];

	paths[0][0] = 1;
	paths[0][1] = 2;
	paths[0][2] = 3;
	paths[0][3] = 4;
	paths[0][4] = 5;
	paths[0][5] = 6;
	paths[0][6] = 7;
	paths[0][7] = DISJ;

	paths[1][0] = 4;
	paths[1][1] = DISJ;
	paths[1][2] = DISJ;
	paths[1][3] = 7;
	paths[1][4] = 3;
	paths[1][5] = DISJ;
	paths[1][6] = DISJ;
	paths[1][7] = DISJ;

	print_path(paths[0], size, se);
	print_path(paths[1], size, se);

	remove_sym(paths, size, se);
	printf("\n");

	print_path(paths[0], size, se);
	print_path(paths[1], size, se);
}

int main()
{
	test_remove_sym();
}
