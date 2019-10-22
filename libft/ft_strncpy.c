/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:58:43 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 15:59:24 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t n)
{
	size_t i;

	i = 0;
	while (srcptr[i] && i < n)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	while (i < n)
	{
		destptr[i] = '\0';
		i++;
	}
	return (destptr);
}
