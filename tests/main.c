#include "lem_in.h"

void test_remove_sym()
{
	int **paths;
	int size = 8;
	int i;
	t_startend se;
	t_paths pp;
	int *p1;

	pp.se = (t_startend){0, 7};
	pp.size = 8;
	pp.paths = malloc(sizeof(int *) * 3);
	pp.paths[0] = malloc(sizeof(int) * size);
	pp.paths[1] = malloc(sizeof(int) * size);
	pp.paths[2] = 0;
	p1 = pp.paths[0];

	pp.paths[0][0] = 1;
	pp.paths[0][1] = 2;
	pp.paths[0][2] = 3;
	pp.paths[0][3] = 4;
	pp.paths[0][4] = 5;
	pp.paths[0][5] = 6;
	pp.paths[0][6] = 7;
	pp.paths[0][7] = DISJ;

	pp.paths[1][0] = 4;
	pp.paths[1][1] = DISJ;
	pp.paths[1][2] = DISJ;
	pp.paths[1][3] = 7;
	pp.paths[1][4] = 3;
	pp.paths[1][5] = DISJ;
	pp.paths[1][6] = DISJ;
	pp.paths[1][7] = DISJ;

	t_paths_init_predecessors(&pp);
	print_paths(pp);
	remove_sym(pp);
	printf("\n");
	t_paths_init_predecessors(&pp);
	print_paths(pp);
}

int main()
{
	test_remove_sym();
}
