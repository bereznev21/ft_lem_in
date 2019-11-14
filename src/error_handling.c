/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:53:28 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 14:53:31 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_exit(const char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	assert(int expr, const char *msg)
{
	if (!expr)
		error_exit(msg);
}
