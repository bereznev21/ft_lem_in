/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:07:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 16:07:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strstr(const char *string1, const char *string2)
{
	char	*str1;
	char	*str2;
	int		i;
	int		n;

	str1 = (char *)string1;
	str2 = (char *)string2;
	i = 0;
	n = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		while ((str1[i + n] == str2[n]) && str1[i + n] && str2[n])
			n++;
		if (!str2[n])
			return (str1 + i);
		n = 0;
		i++;
	}
	return (NULL);
}
