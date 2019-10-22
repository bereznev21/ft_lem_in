/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:03:02 by rpoetess          #+#    #+#             */
/*   Updated: 2019/02/03 20:09:13 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	size_t	i;
	char	*mas;

	i = 0;
	mas = (char *)string;
	while (string[i])
	{
		if (string[i] == symbol)
			return (mas + i);
		i++;
	}
	if (symbol == 0)
		return (mas + i);
	return (NULL);
}
