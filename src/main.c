/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/11 19:49:10 by rpoetess         ###   ########.fr       */
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
	n_paths = suurballe(&aj, &paths, lem_in.start, lem_in.end);
//	printf("total disjoint paths: %d\n", n_paths);
	lem_in_output(paths, aj, lem_in);
//	t_matrix_del(&aj);
//	t_matrix_del(&paths);
//	t_array_del(&lem_in.rooms);
}

int		main(void)
{
	int fd;

//	fd = open("maps/generated/big2.map", O_RDONLY);
	fd = open("test_map", O_RDONLY);
	lem_in_main(fd);
	close(fd);
	return (0);
}
