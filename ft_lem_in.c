/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/22 22:38:40 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_free(t_start *start)
{
	free(start->start);
	free(start->leaks);
	free(start->rooms);
	free(start->end);
	free(start);
}

void	ft_free_int(int **map, int width)
{
	int	i;

	i = 0;
	(void)width;
	while (i < width)
		free(map[i++]);
	free(map);
}

void	ft_free_char(char **map, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(map[i++]);
	free(map);
}

int		ft_init_struct(t_start *start)
{
	start->num_rooms = 0;
	start->num_leaks = 0;
	start->rooms = ft_strdup("");
	start->leaks = ft_strdup("");
	return (1);
}

int		main(void)
{
	t_start	*start;
	t_map	*map;

	if (!(start = (t_start*)malloc(sizeof(*start))))
		return (0);
	if (!(map = (t_map*)malloc(sizeof(*map))))
		return (0);
	if (ft_init_struct(start) == 0)
		//strerror
		return (-1);
	if (ft_read_map(start) != 1)
		//strerror
		return (-1);
	//printf("%s\n", start->start);
	//printf("%s\n", start->rooms);
	//printf("%s\n", start->leaks);
	//printf("%s\n", start->end);
	ft_crt_map_room(start, map);
	ft_wrt_map_leaks(start, map);
	ft_free_int(map->map, start->num_rooms);
	ft_free(start);
	free(map);
	return (0);
}
