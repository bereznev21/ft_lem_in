/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:05:18 by rpoetess          #+#    #+#             */
/*   Updated: 2019/02/03 20:05:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strnstr(const char *string1, const char *string2, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;
	int		n;

	str1 = (char*)string1;
	str2 = (char*)string2;
	i = 0;
	n = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < len)
	{
		while (str1[i + n] == str2[n] && (i + n < len)
		&& str1[i + n] && str2[n])
			n++;
		if (str2[n] == '\0')
			return (str1 + i);
		n = 0;
		i++;
	}
	return (NULL);
}
