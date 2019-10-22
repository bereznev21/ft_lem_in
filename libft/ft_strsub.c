/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:23:52 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:23:53 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*arr;
	unsigned int	l;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s + start);
	if (l >= len)
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			arr[i] = s[start + i];
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
