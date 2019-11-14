#include "lem_in.h"

int		lem_in_count_steps(int **all_paths, t_lem_in lem_in)
{
	int			i;
	int			max;
	int			*len_table;
	int			*lems_in_rooms;
	t_matrix	paths_table;

	t_matrix_init(&paths_table, all_paths->m_alloc, all_paths->n_alloc);
	ft_crt_len_table(*all_paths, lem_in, &paths_table, &len_table);
	ft_calc_lems(*all_paths, lem_in, len_table, &lems_in_rooms);
	i = ft_srch_max1(lems_in_rooms, all_paths->m);
	max = len_table[i];
	free(len_table);
	free(lems_in_rooms);
	return (max);
}

int		**lem_in_solve(t_matrix *aj, t_lem_in lem_in)
{
	int	steps;
	int	steps_result;
	int i;
	int **paths;
	int **paths_new;

	steps_result = INT_MAX;
	paths = malloc(sizeof(int*));
	*paths = 0;
	i = -1;
	while (++i < lem_in.ants)
	{
		paths_new = suurballe_next(*aj, paths, lem_in.se);
		if (!paths_new)
			break ;
		paths = paths_new;
		steps = lem_in_count_steps(paths, lem_in);
		if (steps_result < steps)
			return (paths);
		steps_result = steps;
	}
	return (paths);
}
