/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/23 21:28:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "lem_in.h"
# include "libft/includes/libft.h"

void ft_free(t_start *start)
{
	free(start->start);
	free(start->leaks);
	free(start->rooms);
	free(start->end);
	free(start);
}

void ft_free_int(int **map, int width)
{
	int i;

	i = 0;
	(void)width;
	while (i < width)
		free(map[i++]);
	free(map);
}

void ft_free_char(char **map, int width)
{
	int i;

	i = 0;
	while (i < width)
		free(map[i++]);
	free(map);
}

int ft_init_struct(t_start *start)
{
	start->num_rooms = 0;
	start->num_leaks = 0;
	start->rooms = ft_strdup("");
	start->leaks = ft_strdup("");
	return (1);
}

void ft_print_matrix(int **map, int width)
{
	int i;
	int j;

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

void ft_zero_map(int **map, int width)
{
	int i;
	int j;

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

int main(void)
{
	t_start start;
	t_matrix cap;
	t_matrix flow;
	int fd;

	ft_init_struct(&start);
	fd = open("map", O_RDONLY);
	ft_read_map(&start, fd);
	close(fd);
	ft_crt_map_room(&start);
	t_matrix_init(&cap, start.num_rooms); // create empty matrix
	ft_wrt_map_leaks(&start, &cap); //fill matrix;
	t_matrix_print(&cap);

	flow = push_relabel(&cap, start.start, start.end);
	t_matrix_print(&flow);
	return (0);
}
