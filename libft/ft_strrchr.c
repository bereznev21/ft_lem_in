/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:09:25 by rpoetess          #+#    #+#             */
/*   Updated: 2019/02/03 20:09:27 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*fnd;
	char	*mas;

	i = 0;
	mas = (char *)s;
	fnd = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			fnd = mas + i;
		i++;
	}
	if (c == '\0')
		return (mas + i);
	if (!fnd)
		return (NULL);
	return (fnd);
}
