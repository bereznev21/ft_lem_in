/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:25:56 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:25:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*arr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(arr) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (arr)
	{
		while (s1[i])
		{
			arr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			arr[i + j] = s2[j];
			j++;
		}
		arr[i + j] = '\0';
		return (arr);
	}
	return (NULL);
}
