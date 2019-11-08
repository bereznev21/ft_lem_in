/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 19:23:54 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "lem_in.h"

void	lem_in_main(int fd)
{
	t_lem_in lem_in;
	t_matrix aj; // adjacency matrix
	t_matrix paths;
	int n_paths;

	(void)n_paths;
	aj = lem_in_read(fd, &lem_in);
//	printf("Start: %d End: %d\n\n", lem_in.start, lem_in.end);
//	n_paths = suurballe(&aj, &paths, lem_in.start, lem_in.end);
	find_path(&aj, &paths, lem_in.start, lem_in.end);
//	printf("%d %d\n", aj.m, aj.n);
//	printf("total disjoint paths: %d\n", n_paths);
//	t_matrix_print(&paths);
	lem_in_output(paths, aj, lem_in);
	ft_free(&lem_in, &aj, &paths);
}

void	test_bf(int fd)
{
	t_lem_in lem_in;
	t_matrix aj;
	t_matrix paths;
	//int n_paths;
	int k;
	int i;

	aj = lem_in_read(fd, &lem_in);
	//t_matrix_print(&aj);
	//printf("Start: %d End: %d\n\n", lem_in.start, lem_in.end);
	bf_shortest_path(&aj, &paths, lem_in.start, lem_in.end);
	//t_matrix_print(&paths);

	k = lem_in.start;
	while (k != lem_in.end)
	{
		i = -1;
		while (++i < aj.m)
		{
			if (paths.data[k][i])
			{
				k = i;
				break ;
			}
		}
		if (i == aj.m)
		{
			printf("path not found\n");
			exit(1);
		}
	}
	printf("path exists\n");
}

int		main(void)
{
	int fd;

//	fd = open("maps/map3", O_RDONLY);
	fd = open("maps/generated/test.map", O_RDONLY);
	lem_in_main(fd);
	close(fd);
	return (0);
}
