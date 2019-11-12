/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:34 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/12 20:26:28 by rpoetess         ###   ########.fr       */
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

void	ft_print_ans(int num_len, char *room_name)
{
//	int		len;
	char	*res;
	char	*num;

	res = ft_strdup("");
	res = ft_strjoin_left("L", res);
	num = ft_itoa(num_len);
	res = ft_strjoin_right(res, num);
	res = ft_strjoin_right(res, "-");
	res = ft_strjoin_right(res, room_name);
	res = ft_strjoin_right(res, " ");
	ft_putstr(res);
	free(res);
	free(num);
}

void	ft_print_ants(t_matrix condition_of_ants,
			t_matrix paths_table, t_lem_in lem_in)
{
	int		i;
	int		j;
	int		num;

	i = -1;
	j = 0;
	num = 0;
	while (++i < condition_of_ants.m && condition_of_ants.data[i][j] != DISJ)
	{
		while (j < condition_of_ants.n && condition_of_ants.data[i][j] != DISJ)
		{
			if (condition_of_ants.data[i][j] != 0)
			{
				num = paths_table.data[i][j];
				ft_print_ans(condition_of_ants.data[i][j], ((t_room*)t_array_get(&lem_in.rooms, num))->name);
				/*ft_putchar('L');
				ft_putnbr(condition_of_ants.data[i][j]);
				ft_putchar('-');
				ft_putstr(((t_room*)t_array_get(&lem_in.rooms, num))->name);
				ft_putchar(' ');*/
			}
			j++;
		}
		j = 0;
	}
	//ft_putchar('\n');
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
//	t_matrix_print(&paths_table);
	t_matrix_init(&condition_of_ants, paths_table.m, paths_table.n);
	while (ants > 0)
	{
		i = 0;
		//while (i < paths_table.m)
		while (paths_table.data[i][0] != DISJ)
		//while (lems_in_rooms[i] > 0)
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
		ft_print_ants(condition_of_ants, paths_table, lem_in);
		ft_putchar('\n');
	//	t_matrix_print(&condition_of_ants);
	}
	while (max_path-- >= 0)
	{
		i = -1;
		while (++i < paths_table.n)
			ft_move_leams_in_path(&condition_of_ants, paths_table, i);
		ft_print_ants(condition_of_ants, paths_table, lem_in);
		//if (max_path != 0)
		//	ft_putchar('\n');
	}
	//ft_free_matrix(&condition_of_ants);
}
