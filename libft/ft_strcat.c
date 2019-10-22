/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:04:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 20:04:59 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	size_t i;
	size_t n;

	n = 0;
	i = 0;
	while (destptr[i])
		i++;
	while (srcptr[n])
	{
		destptr[i + n] = srcptr[n];
		n++;
	}
	destptr[i + n] = '\0';
	return (destptr);
}
