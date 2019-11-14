#include "lem_in.h"

int		lem_in_count_steps(t_matrix *all_paths, t_lem_in lem_in)
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

int		lem_in_solve(t_matrix *aj, t_matrix *all_paths, t_lem_in lem_in)
{
	int	steps;
	int	steps_result;
	int	status;
	int i;

	steps_result = INT_MAX;
	t_matrix_init_zero(all_paths, aj->m, aj->n);
	i = -1;
	while (++i < lem_in.ants)
	{
		status = suurballe_next(*aj, all_paths, lem_in.se);
		if (!status)
			break ;
		steps = lem_in_count_steps(all_paths, lem_in);
		if (steps_result < steps)
			return (steps_result);
		steps_result = steps;
	}
	return (steps_result);
}
