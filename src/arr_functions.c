/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:31:08 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/15 19:04:56 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_srch_min(int *len_table)
{
	int min;
	int i;
	int	i_min;

	i = -1;
	i_min = 0;
	min = len_table[0];
	while (len_table[++i] != DISJ)
	{
		if (len_table[i] < min)
		{
			min = len_table[i];
			i_min = i;
		}
	}
	return (i_min);
}

int		ft_srch_max(int *len_table, int len)
{
	int max;
	int i;

	i = 0;
	max = len_table[0];
	while (i < len && len_table[i] != DISJ)
	{
		if (len_table[i] > max)
			max = len_table[i];
		i++;
	}
	return (max);
}

int		ft_srch_max1(int *len_table, int len)
{
	int max;
	int max_i;
	int i;

	i = 0;
	max_i = 0;
	max = len_table[0];
	while (i < len)
	{
		if (len_table[i] > max)
		{
			max = len_table[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}
