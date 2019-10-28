/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:00:48 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/17 17:00:50 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *ret;

	ret = malloc(new_size);
	if (ret)
		ft_memcpy(ret, ptr, old_size);
	else
		return (0);
	free(ptr);
	return (ret);
}
