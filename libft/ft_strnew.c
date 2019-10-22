/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:14:35 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:14:37 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr)
	{
		arr = ft_memset(arr, '\0', size + 1);
		return (arr);
	}
	return (NULL);
}
