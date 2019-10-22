/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:27:11 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:27:16 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*arr;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\n'
	|| s[len - 1] == '\t') && len)
		len--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && len)
	{
		i++;
		len--;
	}
	arr = ft_strsub(s, i, len);
	return (arr);
}
