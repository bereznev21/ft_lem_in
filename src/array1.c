/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:04:11 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/17 23:04:26 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_arr_int(int **str, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(str[i++]);
	free(str);
}