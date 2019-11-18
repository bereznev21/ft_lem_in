/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:49 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 14:44:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include "libft/includes/libft.h"

void	ft_move_lems_in_path1(int *condition_of_ants, int path_i, t_paths paths)
{
	int	k;
	int	k_prev;

	k = paths.se.end;
	while (k != paths.se.start)
	{
		k_prev = paths.paths_rev[path_i][k];
		condition_of_ants[k] = condition_of_ants[k_prev];
		k = k_prev;
	}
	condition_of_ants[k] = DISJ;
}

void	ft_print_ants(int **condition_of_ants, int **paths, t_lem_in lem_in)
{
	int	begin;
	int	i;
	int	num;

	i = -1;
	while (paths[++i])
	{
		begin = lem_in.se.start;
		while (begin != lem_in.se.end)
		{
			if (condition_of_ants[i][begin] != DISJ)
			{
				num = paths[i][begin];
				ft_print_ans(condition_of_ants[i][begin],
					((t_room*)t_array_get(&lem_in.rooms, num))->name);
			}
			begin = paths[i][begin];
		}
	}
}

void	ft_print_lems1(int max_path, t_paths paths,
			int **condition_of_ants, t_lem_in lem_in)
{
	int	i;

	if (max_path > 0)
		while (max_path >= 0)
		{
			i = -1;
			while (paths.paths[++i])
				ft_move_lems_in_path1(condition_of_ants[i],
					i, paths);
			ft_print_ants(condition_of_ants, paths.paths, lem_in);
			if (max_path > 1)
				ft_putchar('\n');
			max_path--;
		}
}

void	ft_print_lems(int *lems_in_rooms,
			t_paths paths, t_lem_in lem_in, int max_path)
{
	int	i;
	int	lem_num;
	int	**condition_of_ants;

	lem_num = 0;
	condition_of_ants = ft_init_arr_2_zero(arr_2_len(paths.paths), paths.size);
	while (lem_in.ants > 0)
	{
		i = -1;
		while (paths.paths[++i])
		{
			ft_move_lems_in_path1(condition_of_ants[i],
				i, paths);
			if (lems_in_rooms[i] > 0 && lem_in.ants-- > 0)
			{
				condition_of_ants[i][paths.se.start] = ++lem_num;
				lems_in_rooms[i]--;
			}
		}
		ft_print_ants(condition_of_ants, paths.paths, lem_in);
		max_path--;
		ft_putchar('\n');
	}
	ft_print_lems1(max_path, paths, condition_of_ants, lem_in);
	ft_free_arr_int(condition_of_ants, arr_2_len(paths.paths));
}

void	lem_in_output(t_paths paths, t_matrix aj, t_lem_in lem_in)
{
	int	max_path;
	int	*lems_in_rooms;

	max_path = ft_calc_lems(paths, aj, &lems_in_rooms, lem_in);
	ft_putchar('\n');
	ft_print_lems(lems_in_rooms, paths, lem_in, max_path);
	free(lems_in_rooms);
}
