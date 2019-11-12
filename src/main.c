/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/12 17:47:42 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "lem_in.h"

void lem_in_main(int fd, UINT flags)
{
	t_lem_in lem_in;
	t_matrix aj; // adjacency matrix
	t_matrix paths;
	int n_paths;

	aj = lem_in_read(fd, &lem_in, flags & FLAG_PRINT_INPUT);
	if (flags & FLAG_DEBUG)
		printf("Start: %d End: %d\n\n", lem_in.start, lem_in.end);
	//if (lem_in.ants > 1)
	//	n_paths = suurballe(&aj, &paths, lem_in.start, lem_in.end);
	//else
	{
		find_path(&aj, &paths, lem_in.start, lem_in.end);
		n_paths = 1;
	}
	if (flags & FLAG_DEBUG)
		printf("total disjoint paths: %d\n", n_paths);
	lem_in_output(paths, aj, lem_in);
	t_matrix_del(&aj);
	t_matrix_del(&paths);
	t_array_del(&lem_in.rooms);
}

int parse_av(int ac, char **av, UINT *flags)
{
	int fd;
	char *arg;
	char *f_name;

	*flags = FLAG_PRINT_INPUT;
	f_name = 0;
	if (ac < 2)
		return (0);
	ac--;
	av++;
	while (ac--)
	{
		arg = *av++;
		if (!ft_strcmp("-d", arg))
			*flags |= FLAG_DEBUG;
		else if (!ft_strcmp("-i", arg))
			*flags ^= FLAG_PRINT_INPUT;
		else if (!f_name)
			f_name = arg;
		else
		{
			ft_putendl_fd("invalid args", STDERR_FILENO);
			exit(1);
		}
	}
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("can't open file", STDERR_FILENO);
		exit(1);
	}
	return (fd);
}

int main(int ac, char **av)
{
	int fd;
	UINT flags;

	fd = parse_av(ac, av, &flags);
	lem_in_main(fd, flags);
	close(fd);
	return (0);
}
