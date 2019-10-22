/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:21:42 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:21:45 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*m;

	i = 0;
	if (s && f)
	{
		l = ft_strlen(s);
		if ((m = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
			return (NULL);
		while (s[i])
		{
			m[i] = f(i, s[i]);
			i++;
		}
		m[i] = '\0';
		return (m);
	}
	return (NULL);
}
