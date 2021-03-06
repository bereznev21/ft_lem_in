/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:12:26 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 14:17:57 by rpoetess         ###   ########.fr       */
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
	{
		ft_strsplit_clear(split);
		return (0);
	}
	assert(get_room_idx(*rooms, split[0]) < 0, "room name conflict");
	room = (t_room){
		ft_strdup(split[0]),
		ft_atoi(split[1]),
		ft_atoi(split[2])};
	t_array_push(rooms, &room);
	ft_strsplit_clear(split);
	return (1);
}

t_array		read_rooms(int fd, t_startend *se, char **line, UINT print_input)
{
	int		i;
	t_array	rooms;

	t_array_init(&rooms, sizeof(t_room));
	i = 0;
	while (1)
	{
		free(*line);
		assert(get_next_line(fd, line) > 0, "failed read room");
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
			assert((split = ft_strsplit(*line, '-')) != NULL, "mem err");
			assert(ft_len((void **)split) == 2, "invalid road");
			assert(get_room_idx(rooms, split[0]) >= 0, "room not found");
			assert(get_room_idx(rooms, split[1]) >= 0, "room not found");
			t_matrix_set(&aj, get_room_idx(rooms, split[0]),
						get_room_idx(rooms, split[1]), 1);
			ft_strsplit_clear(split);
		}
		free(*line);
		if (get_next_line(fd, line) <= 0)
			break ;
		if (print_input)
			ft_putendl(*line);
	}
	return (aj);
}

t_matrix	lem_in_read(int fd, t_lem_in *lem_in)
{
	char *line_buff;
	char **line;
	UINT print_input;
	char *itoa;

	lem_in->se.start = -1;
	lem_in->se.end = -1;
	print_input = lem_in->flags & FLAG_PRINT_INPUT;
	line = &line_buff;
	while (1)
	{
		assert(get_next_line(fd, line) > 0, "bad data");
		if (print_input)
			ft_putendl(*line);
		if (**line != '#')
			break ;
		free(*line);
	}
	lem_in->ants = ft_atoi(*line);
	assert(!ft_strcmp((itoa = ft_itoa(lem_in->ants)), *line), "no ants found");
	free(itoa);
	lem_in->rooms = read_rooms(fd, &lem_in->se, line, print_input);
	assert(lem_in->se.start >= 0, "start not found");
	assert(lem_in->se.end >= 0, "end not found");
	return (read_roads(fd, lem_in->rooms, line, print_input));
}
