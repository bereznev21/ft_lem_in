/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:05:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/15 19:41:03 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
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
*/
int		lem_in_count_steps(t_paths all_paths, t_matrix aj, t_lem_in lem_in)
{
	int	max_path;
	int	*lems_in_rooms;

	max_path = ft_calc_lems1(all_paths, aj, &lems_in_rooms, lem_in);
	return (max_path);
}

t_paths	lem_in_solve(t_matrix *aj, t_lem_in lem_in)
{
	int	steps;
	int	steps_result;
	int i;
	t_paths pp;

	steps_result = INT_MAX;
	pp.paths = malloc(sizeof(int*));
	pp.paths[0] = 0;
	pp.se = lem_in.se;
	pp.size = aj->n;
	i = -1;
	while (++i < lem_in.ants)
	{
		if (!suurballe_next(*aj, &pp))
			break ;
		steps = lem_in_count_steps(pp, *aj, lem_in);
		if (steps_result < steps)
			return (pp);
		steps_result = steps;
	}
	return (pp);
}
