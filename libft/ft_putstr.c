/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:33:23 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 16:38:20 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	int i;
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	i = 0;
}
