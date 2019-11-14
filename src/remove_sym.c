/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_sym.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:43:00 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 21:35:14 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/includes/libft.h"

void	ft_int_cpy(int	*new_arr, int *old, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		new_arr[i] = old[i];
}

int		ft_check_path(int **arr_paths, t_matrix *aj, int i, t_startend se)
{
	int	j;
	int	node;
	int	new_i;
	int	*new_path1;
	int	*new_path2;

	node = se.start;
	while (node != se.end)
	{
		new_i = i;
		while (++new_i < aj->m)
		{
			if (new_path1[new_i] == node)
			{
				new_path1[new_i] = node;
				node = new_i;
				return (1);
			}
		}
	}
	return (0);
}

void	remove_sym(int **arr_paths, t_matrix *aj, t_startend se)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (arr_paths[++i])
	{
		if(ft_check_path(arr_paths, aj, i, se))
		{
			i = -1;
			j = -1;
			break ;
		}
	}
}

/*
ABCDEFGH
AEDH
*/

/*
ABCDH
AEFGH
*/