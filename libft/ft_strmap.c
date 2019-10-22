/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:19:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:19:43 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*m;

	i = 0;
	if (s && f)
	{
		l = ft_strlen(s);
		if ((m = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
			return (NULL);
		while (s[i])
		{
			m[i] = f(s[i]);
			i++;
		}
		m[i] = '\0';
		return (m);
	}
	return (NULL);
}
