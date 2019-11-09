/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:34 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 19:32:47 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void	ft_print_arr(int *lems_in_rooms, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(lems_in_rooms[i]);
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_ants(t_matrix condition_of_ants,
			t_matrix paths_table, t_lem_in lem_in)
{
	int	i;
	int	j;
	int num;

	i = -1;
	j = 0;
	num = 0;
	ft_putchar('\n');
	while (++i < condition_of_ants.m && condition_of_ants.data[i][j] != DISJ)
	{
		while (j < condition_of_ants.n && condition_of_ants.data[i][j] != DISJ)
		{
			if (condition_of_ants.data[i][j] != 0)
			{
				num = paths_table.data[i][j];
				ft_putchar('L');
				ft_putnbr(condition_of_ants.data[i][j]);
				ft_putchar('-');
				ft_putstr(((t_room*)t_array_get(&lem_in.rooms, num))->name);
				ft_putchar(' ');
			}
			j++;
		}
		j = 0;
	}
}

void	ft_print_lems(int *lems_in_rooms,
			t_matrix paths_table, t_lem_in lem_in, int max_path)
{
	int			i;
	int			lem_num;
	int			ants;
	t_matrix	condition_of_ants;

	ants = lem_in.ants;
	lem_num = 0;
	i = 0;
	t_matrix_init(&condition_of_ants, paths_table.m, paths_table.n);
	while (ants > 0)
	{
		//while (i < paths_table.n)
		while (lems_in_rooms[i] > 0)
		{
			ft_move_leams_in_path(&condition_of_ants, paths_table, i);
			if (lems_in_rooms[i] > 0 && ants > 0)
			{
				lem_num++;
				condition_of_ants.data[i][0] = lem_num;
				lems_in_rooms[i]--;
				ants--;
			}
			i++;
		}
		//t_matrix_print(&condition_of_ants);
		ft_print_ants(condition_of_ants, paths_table, lem_in);
		i = 0;
	}
	while (max_path-- > 0)
	{
		i = -1;
		while (++i < paths_table.n)
			ft_move_leams_in_path(&condition_of_ants, paths_table, i);
		ft_print_ants(condition_of_ants, paths_table, lem_in);
	}
	//ft_free_matrix(&condition_of_ants);
}
