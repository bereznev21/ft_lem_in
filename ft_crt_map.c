/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:48:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/24 20:09:49 by rpoetess         ###   ########.fr       */
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
	start->num_rooms = i / 3 + 1;
	map->size = start->num_rooms;
	//printf("%d\n", start->num_rooms);
	i = 0;
	if (!(map->matrix = (int**)malloc(sizeof(int*) * (map->size))))
		return ;
	while (i < map->size)
	{
		if (!(map->matrix[i] = (int*)malloc(sizeof(int) * (map->size))))
			return ;
		//ft_bzero(map->map[i], start->num_rooms);
		i++;
	}
	ft_zero_map(map->matrix, map->size);
	//ft_free_char(res, start->num_rooms * 3);
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
		//printf("%d %d\n", a, b);
	/*	ft_putnbr(a);
		ft_putchar(' ');
		ft_putnbr(a);
		ft_putchar('\n');
	*/
		map->matrix[a][b] = 1;
		map->matrix[b][a] = 1;
		i++;
	}
	start->num_leaks = i;
	map->start = 0;
	i = 0;
	//printf("%d\n", start->num_leaks);
	ft_free_char(res, start->num_leaks);
}
