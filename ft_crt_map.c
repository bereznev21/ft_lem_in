/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:48:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/24 22:22:32 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/includes/libft.h"

void	ft_crt_map_room(t_start *start)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_strsplit(start->rooms, ' ');
	while (res[i])
		i++;
	start->num_rooms = i / 3 + 1;
}

void	ft_wrt_map_leaks(t_start *start, t_matrix *leaks)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_strsplit(start->leaks, ' ');
	while (res[i])
	{
		t_matrix_set(leaks, res[i][0] - '0', res[i][2] - '0');
		i++;
	}
	start->num_leaks = i;
//	map->start = 0;
	i = 0;
	//printf("%d\n", start->num_leaks);
//	ft_free_char(res, start->num_leaks);
}
