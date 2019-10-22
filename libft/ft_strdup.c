/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:56:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 15:56:35 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char *n_str;

	n_str = (char*)malloc(sizeof(*n_str) * (ft_strlen(str) + 1));
	if (!n_str)
		return (NULL);
	n_str = ft_strcpy(n_str, str);
	return (n_str);
}
