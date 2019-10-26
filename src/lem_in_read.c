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

int get_room_idx(t_room *rooms, int cnt, const char *name)
{
	int i;

	i = -1;
	while (++i < cnt)
		if (!ft_strcmp(name, rooms[i].name))
			return (i);
	return (-1);
}

t_room *read_rooms(int fd, int cnt, int *start, int *end)
{
	t_room *rooms;
	char *line;
	char **split;
	int i;

	rooms = malloc(sizeof(t_room) * cnt);
	i = 0;
	while (i < cnt)
	{
		assert(ft_get_next_line(fd, &line) > 0, "failed read room");
		if (!ft_strcmp(line, "##start"))
			*start = i;
		if (!ft_strcmp(line, "##end"))
			*end = i;
		if (line[0] == '#')
			continue;
		split = ft_strsplit(line, ' ');
		free(line);
		assert(ft_len((void **)split) == 3, "bad room format");
		assert(get_room_idx(rooms, i, split[0]) < 0, "room name conflict");
		rooms[i++] = (t_room){split[0], ft_atoi(split[1]), ft_atoi(split[2])};
		free(split[1]);
		free(split[2]);
	}
	return (rooms);
}

t_matrix read_roads(int fd, t_room *rooms, int cnt)
{
	t_matrix aj;
	int i;
	char *line;
	char **split;

	t_matrix_init(&aj, cnt, cnt);
	i = -1;
	while (++i < cnt)
	{
		assert(ft_get_next_line(fd, &line) > 0, "failed read road");
		split = ft_strsplit(line, '-');
		free(line);
		t_matrix_set(&aj,
					 get_room_idx(rooms, cnt, split[0]),
					 get_room_idx(rooms, cnt, split[1]), 1);
	}
	return (aj);
}

t_matrix lem_in_read(int fd, int *start, int *end, t_room **rooms)
{
	char *line;
	int cnt;

	(void)fd;
	(void)start;
	(void)end;

	while(1)
	{
		assert(ft_get_next_line(fd, &line) > 0, "bad data");
		if (line[0] != '#')
			break ;
	}
	cnt = ft_atoi(line);
	free(line);
	assert(cnt > 1, "expected more then 1 rooms");
	*rooms = read_rooms(fd, cnt, start, end);
	return read_roads(fd, *rooms, cnt);
}
