/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:34 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 17:22:14 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
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
