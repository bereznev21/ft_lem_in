#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"


void t_matrix_init(t_matrix *m, int n)
{
	int i;

	m->n = n;
	m->data = malloc(sizeof(int *) * m->n);
	i = -1;
	while (++i < m->n)
	{
		m->data[i] = malloc(sizeof(int) * m->n);
		ft_bzero(m->data[i], m->n * sizeof(int));
	}
}

void t_matrix_print(t_matrix *m)
{
	int i;
	int j;

	i = -1;
	while (++i < m->n)
	{
		j = -1;
		while (++j < m->n)
		{
			printf("%d\t", m->data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void t_matrix_set(t_matrix *m, int i, int j)
{
	m->data[i][j] = 1;
	m->data[j][i] = 1;
}

void t_matrix_fill(t_matrix *m)
{
	t_matrix_set(m, 0, 1);
	t_matrix_set(m, 0, 2);
	t_matrix_set(m, 1, 4);
	t_matrix_set(m, 2, 3);
	t_matrix_set(m, 2, 4);
	t_matrix_set(m, 3, 5);
	t_matrix_set(m, 4, 5);
}

void lem_in_test()
{
	t_matrix map;
	t_matrix flow;

	t_matrix_init(&map, 6);

	t_matrix_fill(&map);
	t_matrix_print(&map);
	flow = push_relabel(&map, 0, 5);
	t_matrix_print(&flow);
}
