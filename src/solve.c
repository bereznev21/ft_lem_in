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

t_paths	lem_in_solve(t_matrix *aj, t_lem_in lem_in)
{
	int		steps;
	int		steps_result;
	int		i;
	t_paths pp;

	steps_result = INT_MAX;
	t_paths_init(&pp, lem_in.se, aj->n);
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
