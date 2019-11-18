/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:30:35 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 17:18:34 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_put_end(int **roads, int end)
{
	int n;

	n = 0;
	while ((*roads)[n] != DISJ)
		n++;
	(*roads)[n] = end;
}

int		arr_2_len(int **arr)
{
	int len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
