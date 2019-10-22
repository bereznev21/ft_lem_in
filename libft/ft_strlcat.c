/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:06:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/31 15:25:32 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *destptr, const char *srcptr, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (destptr[len] && len < size)
		len += 1;
	i = len;
	while (srcptr[len - i] && len + 1 < size)
	{
		destptr[len] = srcptr[len - i];
		len += 1;
	}
	if (i < size)
		destptr[len] = '\0';
	return (i + ft_strlen(srcptr));
}
