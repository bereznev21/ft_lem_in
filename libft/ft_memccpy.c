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

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;
	size_t			i;

	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	i = 0;
	if (s1 == s2)
		return (s1);
	while (i < n)
	{
		cpy1[i] = cpy2[i];
		if (cpy2[i] == (unsigned char)c)
			return (cpy1 + i + 1);
		i++;
	}
	return (NULL);
}
