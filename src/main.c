/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/12 22:36:50 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "lem_in.h"

void	lem_in_main(int fd, UINT flags)
{
	t_lem_in	lem_in;
	t_matrix	aj;
	t_matrix	paths;
	int			n_paths;

	aj = lem_in_read(fd, &lem_in, flags & FLAG_PRINT_INPUT);
	if (flags & FLAG_DEBUG)
		printf("Start: %d End: %d\n\n", lem_in.se.start, lem_in.se.end);
	//if (lem_in.ants > 1)
	//	n_paths = suurballe(&aj, &paths, lem_in.se);
		n_paths = lem_in_solve(&aj, &paths, lem_in);
	/*
	{
		find_path(&aj, &paths, lem_in.se);
		n_paths = 1;
	}
	*/
	if (flags & FLAG_DEBUG)
		printf("total disjoint paths: %d\n", n_paths);
	lem_in_output(paths, aj, lem_in);
	t_matrix_del(&aj);
	t_matrix_del(&paths);
	t_array_del(&lem_in.rooms);
}

int		parse_av(int ac, char **av, UINT *flags)
{
	int		fd;
	char	*arg;
	char	*f_name;

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
			error_exit("invalid args");
	}
	if ((fd = open(f_name, O_RDONLY)) < 0)
		error_exit("can't open file");
	return (fd);
}

int		main(int ac, char **av)
{
	int		fd;
	UINT	flags;

	fd = parse_av(ac, av, &flags);
	lem_in_main(fd, flags);
	close(fd);
	return (0);
}
