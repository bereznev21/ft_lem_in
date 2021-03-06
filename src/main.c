/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 17:22:23 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lem_in.h"

void	clean_rooms(t_array rooms)
{
	int i;

	i = -1;
	while (++i < rooms.count)
		free(((t_room*)t_array_get(&rooms, i))->name);
	t_array_del(&rooms);
}

void	lem_in_main(int fd, UINT flags)
{
	t_lem_in	lem_in;
	t_matrix	aj;
	t_paths		paths;

	lem_in.flags = flags;
	aj = lem_in_read(fd, &lem_in);
	paths = lem_in_solve(&aj, lem_in);
	if (!ft_len((void**)paths.paths))
		error_exit("graph is not connected");
	t_paths_init_rev(&paths);
	lem_in_output(paths, aj, lem_in);
	if (flags & FLAG_PRINT_PATHS)
		t_paths_print(paths);
	t_matrix_del(&aj);
	t_paths_del(&paths);
	clean_rooms(lem_in.rooms);
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
		if (!ft_strcmp("-i", arg))
			*flags ^= FLAG_PRINT_INPUT;
		else if (!ft_strcmp("-p", arg))
			*flags ^= FLAG_PRINT_PATHS;
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
