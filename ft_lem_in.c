/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/25 22:38:29 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_free(t_start *start)
{
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

void	ft_print_int_map(int **map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		while (j < width)
		{
			//printf("%d", map[i][j]);
			ft_putnbr(map[i][j]);
			j++;
		}
		//printf("\n");
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_zero_map(int **map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		while (j < width)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

/*
void	ft_src_roads(t_map *map, int i, int j)
{
	
}

void	ft_start_algo(t_start *start, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			if (map->matrix[i][j] == 1)
				ft_src_roads(map, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
*/

/*
void	ft_start_algo(t_start *start, t_map *map)
{
	int	i;
	int j;

	i = map->
}
*/

void	ft_put_end(int **map_road, int i, int j)
{
	int	n;

	n = 0;
	while (map_road[i][n] > 0)
		n++;
	map_road[i][n] = j;
}

void	ft_wrt_ans_map(t_map *map)
{
	int		i;
	int		j;
	int matrix[6][6] =
	{
	{0, 1, 1, 0, 0, 0},
	{-1, 0, 0, 0, 1, 0},
	{-1, 0, 0, 1, 0, 0},
	{0, 0, -1, 0, 0, 1},
	{0, -1, 0, 0, 0, 1},
	{0, 0, 0, -1, -1, 0}
	};

	i = 0;
	j = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			if (matrix[i][j] == 1)
			{
				//ft_src_roads(map, i, j);
				ft_put_end(map->map_road, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_print_char_map(char **map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		while (j < width)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_take_ans(t_map *map)
{
	int	i;

	i = 0;
	map->map_road = (int**)malloc(sizeof(int*) * map->size);
	while (i < map->size)
	{
		if (!(map->map_road[i] = (int*)malloc(sizeof(int) * (map->size))))
			return ;
		i++;
	}
	ft_zero_map(map->map_road, map->size);
	ft_wrt_ans_map(map);
	ft_print_int_map(map->map_road, map->size);
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
//	ft_crt_map_room(start, map);
//	ft_wrt_map_leaks(start, map);
//	ft_print_int_map(map->matrix, map->size);
	


	//ft_start_algo(start, map);
	ft_putchar('\n');
	ft_take_ans(map);
	ft_free_int(map->matrix, map->size);
	ft_free(start);
	free(map);
	return (0);
}
