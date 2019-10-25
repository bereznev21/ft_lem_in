/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/25 16:25:07 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "lem_in.h"
# include "libft/includes/libft.h"

/*void ft_free(t_start *start)
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
*/
int		ft_init_struct(t_start *start)
{
	start->num_rooms = 0;
	start->num_leaks = 0;
	start->rooms = ft_strdup("");
	start->leaks = ft_strdup("");
	return (1);
}

void	ft_print_matrix(int **map, int width)
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

void	ft_zero_map(int **map, int width)
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

void	ft_print_int_map(t_matrix *roads)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < roads->n)
	{
		while (j < roads->n)
		{
			//printf("%d", map[i][j]);
			ft_putnbr(roads->data[i][j]);
			j++;
		}
		//printf("\n");
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_brake_ans_map(t_matrix *ans)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ans->n)
	{
		while (j < ans->n)
		{
			if (ans->data[i][j] == 1)
				ans->data[i][j] = -1;
			else if (ans->data[i][j] == -1)
				ans->data[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_put_end(t_matrix *roads, int i, int j)
{
	int n;

	n = 0;
	while (roads->data[i][n] > 0)
		n++;
	roads->data[i][n] = j;
}

void	ft_src_roads(t_matrix *ans, t_matrix *map, int k)
{
	int	i;
	int j;

	i = k;
	j = 0;
	
	while (1)
	{
		while (ans->data[i][j] != 1 && j < ans->n)
			j++;
		if (ans->data[i][j] == 1)
			ft_put_end(map, k, j);
		else
			break ;
		i = j;
		j = 0;
	}
}

void	ft_wrt_ans_map(t_matrix *map, t_matrix *ans, int start)
{
	int	j;

	j = -1;
	while (++j < ans->n)
		if (ans->data[start][j] == 1)
		{
			ft_put_end(map, start, j);
			ft_src_roads(ans, map, j);
		}
}

int		main(void)
{
	t_start start;
	t_matrix cap;
	t_matrix ans;
	t_matrix roads;
	int fd;

	ft_init_struct(&start);
	fd = open("map", O_RDONLY);
	ft_read_map(&start, fd);
	close(fd);
	ft_crt_map_room(&start);
	t_matrix_init(&cap, start.num_rooms); // create empty matrix
	ft_wrt_map_leaks(&start, &cap); //fill matrix;
	t_matrix_print(&cap);

	ans = push_relabel(&cap, start.start, start.end);
	//ft_brake_ans_map(&ans);
	t_matrix_print(&ans);

	t_matrix_init(&roads, start.num_rooms);
	ft_wrt_ans_map(&roads, &ans, start.start);
	ft_print_int_map(&roads);
	return (0);
}
