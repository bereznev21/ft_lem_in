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
#include "string.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;
	size_t			i;

	cpy1 = (unsigned char *)(dst);
	cpy2 = (unsigned char *)(src);
	i = 0;
	if (dst <= src && n)
	{
		while (i < n)
		{
			cpy1[i] = cpy2[i];
			i++;
		}
	}
	if (dst > src && n)
	{
		while (n-- > 0)
			cpy1[n] = cpy2[n];
	}
	return (cpy1);
}
