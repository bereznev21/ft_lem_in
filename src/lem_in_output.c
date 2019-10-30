/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/30 18:56:05 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void		ft_sort_paths(int **paths, int *size_paths, int num_patchs, int lems)
{
	int	i;

	i = 0;
	(void)paths;
	while (i < num_patchs)
	{
		if (size_paths[i] < lems)
			while (lems--)
			{
				/* code */
			}
	}
	
}

int			*ft_srh_num_paths(int **paths, int *len, int num_patchs)
{
	int	i;
	int	*size_paths;

	i = 0;
	size_paths = (int*)malloc(sizeof(int) * num_patchs);
	while (i < num_patchs)
	{
		while (paths[i][*len] != -1)
			(*len)++;

		size_paths[i] = *len;
		i++;
	}
	return (size_paths);
}

void	ft_crt_len_table(int **rooms_table, int *len_table)
{
	int i;

	i = 0;
	while (i < )
	{
		/* code */
	}
		
}

void	lem_in_output(t_matrix *aj, int num_patchs, int lems)
{
	int	i;
	int	*len_table;
	int	**rooms_table;

	i = 0;
	ft_crt_len_table(rooms_table, len_table);
	//ft_sort_paths(paths);
	//size_paths = ft_srh_num_paths(paths, &len, num_patchs);
	//ft_print_paths(paths, size_paths, num_patchs, lems);
}
