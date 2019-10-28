#include "stdio.h"
#include "libft.h"
#include "lem_in.h"

void assert(int expr, const char *msg)
{
	if (!expr)
	{
		printf("%s\n", msg);
		exit(1);
	}
}

int get_room_idx(t_array rooms, const char *name)
{
	int i;

	i = -1;
	while (++i < rooms.count)
		if (!ft_strcmp(name, ((t_room *)t_array_get(&rooms, i))->name))
			return (i);
	return (-1);
}

t_array read_rooms(int fd, int *start, int *end, char **line)
{
	t_array rooms;
	t_room room;
	char **split;
	int i;

	t_array_init(&rooms, sizeof(t_room));
	i = 0;
	while (++i)
	{
		assert(ft_get_next_line(fd, line) > 0, "failed read room");
		if (!ft_strcmp(*line, "##start"))
			*start = i;
		if (!ft_strcmp(*line, "##end"))
			*end = i;
		if (*line[0] == '#')
			continue;
		split = ft_strsplit(*line, ' ');
		if (ft_len((void **)split) != 3)
			break;
		free(*line);
		assert(get_room_idx(rooms, split[0]) < 0, "room name conflict");
		room = (t_room){split[0], ft_atoi(split[1]), ft_atoi(split[2])};
		t_array_push(&rooms, &room);
		free(split[1]);
		free(split[2]);
	}
	return (rooms);
}

t_matrix read_roads(int fd, t_array rooms, char **line)
{
	t_matrix aj;
	int i;
	char **split;

	t_matrix_init(&aj, rooms.count, rooms.count);
	i = 0;
	while (1)
	{
		split = ft_strsplit(*line, '-');
		assert(ft_len((void *)split) == 2, "invalid road");
		free(*line);
		assert(get_room_idx(rooms, split[0]) >= 0, "room not found");
		assert(get_room_idx(rooms, split[1]) >= 0, "room not found");
		t_matrix_set(&aj,
					 get_room_idx(rooms, split[0]),
					 get_room_idx(rooms, split[1]), 1);
		if (++i >= rooms.count)
			break;
		assert(ft_get_next_line(fd, line) > 0, "failed read road");
	}
	return (aj);
}

t_matrix lem_in_read(int fd, int *start, int *end, t_array *rooms, int *ants)
{
	char *line;

	(void)fd;
	(void)start;
	(void)end;

	while (1)
	{
		assert(ft_get_next_line(fd, &line) > 0, "bad data");
		if (line[0] != '#')
			break;
	}
	*ants = ft_atoi(line);
	free(line);
	*rooms = read_rooms(fd, start, end, &line);
	return read_roads(fd, *rooms, &line);
}
