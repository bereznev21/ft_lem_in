/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:12:26 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/11 20:52:24 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int			get_room_idx(t_array rooms, const char *name)
{
	int i;

	i = -1;
	while (++i < rooms.count)
		if (!ft_strcmp(name, ((t_room *)t_array_get(&rooms, i))->name))
			return (i);
	return (-1);
}

int			put_room(t_array *rooms, char *line)
{
	char	**split;
	t_room	room;

	split = ft_strsplit(line, ' ');
	if (ft_len((void **)split) != 3)
		return (0);
	assert(get_room_idx(*rooms, split[0]) < 0, "room name conflict");
	room = (t_room){split[0], ft_atoi(split[1]), ft_atoi(split[2])};
	t_array_push(rooms, &room);
	free(split[1]);
	free(split[2]);
	free(split);
	return (1);
}

t_array		read_rooms(int fd, t_startend *se, char **line, UINT print_input)
{
	t_array	rooms;
	int		i;

	t_array_init(&rooms, sizeof(t_room));
	i = 0;
	while (1)
	{
		free(*line);
		assert(ft_get_next_line(fd, line) > 0, "failed read room");
		if (print_input)
			ft_putendl(*line);
		if (!ft_strcmp(*line, "##start"))
			se->start = i;
		if (!ft_strcmp(*line, "##end"))
			se->end = i;
		if (**line == '#')
			continue ;
		++i;
		if (!put_room(&rooms, *line))
			break ;
	}
	return (rooms);
}

t_matrix	read_roads(int fd, t_array rooms, char **line, UINT print_input)
{
	t_matrix	aj;
	char		**split;

	t_matrix_init(&aj, rooms.count, rooms.count);
	while (1)
	{
		if (**line != '#')
		{
			split = ft_strsplit(*line, '-');
			assert(ft_len((void *)split) == 2, "invalid road");
			assert(get_room_idx(rooms, split[0]) >= 0, "room not found");
			assert(get_room_idx(rooms, split[1]) >= 0, "room not found");
			t_matrix_set(&aj, get_room_idx(rooms, split[0]),
						get_room_idx(rooms, split[1]), 1);
			free(split[0]);
			free(split[1]);
			free(split);
		}
		free(*line);
		if (ft_get_next_line(fd, line) <= 0)
			break ;
		if (print_input)
			ft_putendl(*line);
	}
	return (aj);
}

t_matrix	lem_in_read(int fd, t_lem_in *lem_in, UINT print_input)
{
	char *line;

	while (1)
	{
		assert(ft_get_next_line(fd, &line) > 0, "bad data");
		if (print_input)
			ft_putendl(line);
		if (line[0] != '#')
			break ;
		free(line);
	}
	lem_in->ants = ft_atoi(line);
	lem_in->rooms = read_rooms(fd, &lem_in->se, &line, print_input);
	return (read_roads(fd, lem_in->rooms, &line, print_input));
}
