/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:48:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/22 23:03:39 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_crt_map_room(t_start *start, t_map *map)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_strsplit(start->rooms, ' ');
	while (res[i])
		i++;
	start->num_rooms = i / 3;
	i = 0;
	if (!(map->map = (int**)malloc(sizeof(int*) * (start->num_rooms + 1))))
		return ;
	while (i < start->num_rooms)
	{
		if (!(map->map[i] = (int*)malloc(sizeof(int) * (start->num_rooms + 1))))
			return ;
		i++;
	}
	printf("%d\n", start->num_rooms);
	ft_free_char(res, start->num_rooms * 3);
}

void	ft_wrt_map_leaks(t_start *start, t_map *map)
{
	char	**res;
	int		i;
	int		a;
	int		b;

	i = 0;
	res = ft_strsplit(start->leaks, ' ');
	while (res[i])
	{
		a = res[i][0] - '0';
		b = res[i][2] - '0';
		printf("%d %d\n", a, b);
		map->map[a][b] = 1; // seg fault here
		i++;
	}
	start->num_leaks = i;
	map->start = 0;
	i = 0;
	printf("%d\n", start->num_leaks);
	ft_free_char(res, start->num_leaks);
}
