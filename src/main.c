/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/25 23:29:07 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
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
int ft_init_struct(t_start *start)
{
	start->num_rooms = 0;
	start->num_leaks = 0;
	start->end = -1;
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

void ft_print_int_map(t_matrix *roads)
{
	int i;
	int j;

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

void ft_brake_ans_map(t_matrix *ans)
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

void ft_put_end(t_matrix *roads, int i, int j)
{
	int n;

	n = 0;
	while (roads->data[i][n] > 0)
		n++;
	roads->data[i][n] = j;
}

void ft_src_roads(t_matrix *ans, t_matrix *map, int k)
{
	int i;
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
			break;
		i = j;
		j = 0;
	}
}

void ft_wrt_ans_map(t_matrix *map, t_matrix *ans, int start)
{
	int j;

	j = -1;
	while (++j < ans->n)
		if (ans->data[start][j] == 1)
		{
			ft_put_end(map, start, j);
			ft_src_roads(ans, map, j);
		}
}

void collapse_roads(t_matrix *aj, t_matrix *collapse)
{
	int i;

	t_matrix r;

	r = t_matrix_mul(aj, collapse);
	t_matrix_del(aj);
	*aj = r;
	t_matrix_t(collapse);
	r = t_matrix_mul(collapse, aj);
	t_matrix_del(aj);
	*aj = r;
	i = -1;
	while (++i < aj->n)
		aj->data[i][i] = 0;
}

void lem_in_v1(int fd)
{
	t_start start;
	t_matrix aj;
	t_matrix ans;
	t_matrix roads;
	t_matrix collapse_m;

	ft_init_struct(&start);
	ft_read_map(&start, fd);
	ft_crt_map_room(&start);
	t_matrix_init(&aj, start.num_rooms, start.num_rooms); // create empty matrix
	ft_wrt_map_leaks(&start, &aj); //fill matrix;
	printf("start, end: %d->%d\n", start.start, start.end);
	printf("Adjacency matrix:\n");
	t_matrix_print(&aj);
	printf("Expanded graph:\n");
	collapse_m = expand_junctions(&aj);
	t_matrix_print(&aj);
	ans = push_relabel(&aj, start.start, start.end);
	printf("Max flow solution:\n");
	t_matrix_print(&ans);
	collapse_roads(&ans, &collapse_m);
	printf("collapsed solution:\n");
	t_matrix_print(&ans);
	//ft_brake_ans_map(&ans);

	return ; // next is segfault;
	t_matrix_init(&roads, start.num_rooms, start.num_rooms);
	ft_wrt_ans_map(&roads, &ans, start.start);
	printf("Roads:\n");
	ft_print_int_map(&roads);
	return;
}

void lem_in_v2(int fd)
{
	int start;
	int end;
	t_room *rooms;
//	int **paths;
//	int **selected_paths;
	t_matrix aj;

	aj = lem_in_read(fd, &start, &end, &rooms);
	t_matrix_print(&aj);
//	paths = find_paths(&aj, start.start, start.end);
//	selected_paths = select_paths(paths);
//	lem_in_output(selected_paths);
}

int main(void)
{
	int fd;

	fd = open("maps/map", O_RDONLY);
//	lem_in_v1(fd);
	lem_in_v2(fd);
	close(fd);
	return (0);
}
