/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:01:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 16:01:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t num)
{
	size_t i;
	size_t n;

	n = 0;
	i = 0;
	while (destptr[i])
		i++;
	while (srcptr[n] && n < num)
	{
		destptr[i + n] = srcptr[n];
		n++;
	}
	destptr[i + n] = '\0';
	return (destptr);
}
