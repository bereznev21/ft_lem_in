/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:22:59 by rpoetess          #+#    #+#             */
/*   Updated: 2018/11/30 20:23:05 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = b;
	i = 0;
	while (i < n)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return ((void *)buffer);
}
