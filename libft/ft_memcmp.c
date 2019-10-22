/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:51:07 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 15:51:09 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	i = 0;
	m1 = (unsigned char *)memptr1;
	m2 = (unsigned char *)memptr2;
	while (num--)
	{
		if (m1[i] != m2[i])
			return ((int)m1[i] - (int)m2[i]);
		i++;
	}
	return (0);
}
