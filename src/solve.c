/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:05:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 17:46:12 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_count_steps(t_paths all_paths, t_matrix aj, t_lem_in lem_in)
{
	int		max_path;
	int		*lems_in_rooms;

	max_path = ft_calc_lems(all_paths, aj, &lems_in_rooms, lem_in);
	return (max_path);
}

int		check_steps(int steps, int *steps_min, int *local_minimum_alert)
{
	if (*steps_min < steps)
		return (1);
	if (*steps_min > steps)
		*local_minimum_alert = 1;
	else if (++*local_minimum_alert >= 3)
		return (1);
	*steps_min = steps;
	return (0);
}

t_paths	lem_in_solve(t_matrix *aj, t_lem_in lem_in)
{
	int		i;
	t_paths	pp;
	t_paths	pp_prev;
	int		steps_result;
	int		local_minimum_alert;

	local_minimum_alert = 0;
	steps_result = INT_MAX;
	t_paths_init(&pp, lem_in.se, aj->n);
	i = -1;
	while (++i < lem_in.ants)
	{
		pp_prev = t_paths_copy(pp);
		if (!suurballe_next(*aj, &pp))
			break ;
		fprintf(stderr, "steps for i=%d : %d\n", i,
				lem_in_count_steps(pp, *aj, lem_in));
		if (check_steps(lem_in_count_steps(pp, *aj, lem_in),
				&steps_result, &local_minimum_alert))
			break ;
	}
	t_paths_del(&pp);
	return (pp_prev);
}
