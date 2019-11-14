/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:48 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 14:13:38 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/includes/libft.h"

/*
** http://www.macfreek.nl/memory/Disjoint_Path_Finding
*/

int		suurballe_next(t_matrix aj, t_matrix *all_paths, t_startend se)
{
	t_collapse	c;
	t_matrix	path;

	aj = t_matrix_copy(&aj);
	suurballe_reverse_path(&aj, all_paths);
	t_collapse_init(&c, aj.m);
	split_paths_nodes(&aj, all_paths, &c, se);
	if (!find_path(&aj, &path, se))//todo: find_path should delete free memory when path not found
	{
		t_matrix_del(&aj);
		t_array_del(&c.a);
		return (0);
	}
	t_collapse_do(&c, &path);
	t_array_del(&c.a);
	*all_paths = t_matrix_add(all_paths, &path);
	remove_sym(all_paths);
	t_matrix_del(&aj);
	t_matrix_del(&path);
	return (1);
}

int		suurballe(t_matrix *aj, t_matrix *all_paths, t_startend se)
{
	int			i;

	t_matrix_init_zero(all_paths, aj->m, aj->n);
	i = 0;
	while (suurballe_next(*aj, all_paths, se))
		i++;
	return (i);
}

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
