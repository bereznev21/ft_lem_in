#include "lem_in.h"
#include "libft.h"

void		t_matrix_init(t_matrix *mat, int m, int n)
{
	int i;
	int j;

	mat->m = m;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = DISJ;
	}
}

void		t_matrix_init_zero(t_matrix *mat, int m, int n)
{
	int	i;
	int	j;

	mat->m = m;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		j = -1;
		while (++j < mat->n)
			mat->data[i][j] = 0;
	}
}

void		t_matrix_init_identity(t_matrix *mat, int n)
{
	int	i;

	mat->m = n;
	mat->n = n;
	mat->data = malloc(sizeof(int *) * mat->m);
	i = -1;
	while (++i < mat->m)
	{
		mat->data[i] = malloc(sizeof(int) * mat->n);
		ft_bzero(mat->data[i], mat->n * sizeof(int));
		mat->data[i][i] = 1;
	}
}
