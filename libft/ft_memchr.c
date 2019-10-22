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

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*mas;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	mas = (unsigned char *)arr;
	while (i < n)
	{
		if (mas[i] == cc)
			return (mas + i);
		i++;
	}
	return (NULL);
}
