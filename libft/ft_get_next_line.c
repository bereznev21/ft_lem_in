/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:29:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/12 18:58:19 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libft_compat.h"
#include "includes/get_next_line.h"

static int	ft_get_new_line(const int fd, char **line, char **old, int i)
{
	int		j;
	char	*buff;

	j = 0;
	if (i == 0 && (old[fd] == NULL || old[fd][0] == '\0'))
		return (0);
	while ((old[fd][j] != '\0') && (old[fd][j] != '\n'))
		j++;
	if (old[fd][j] == '\n')
	{
		*line = ft_strsub(old[fd], 0, j);
		buff = ft_strdup(old[fd] + j + 1);
		ft_strdel(&old[fd]);
		old[fd] = buff;
	}
	else if (old[fd][j] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(old[fd]);
		ft_strdel(&old[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*old[1];
	char		*new_arr;
	int			i;
	char		*buf;

	i = 0;
	if (!(new_arr = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)) || (fd < 0)
		|| (!line) || ((i = read(fd, 0, 0)) == -1))
		return (-1);
	if (old[fd] == 0)
		old[fd] = ft_strnew(0);
	while ((i = read(fd, new_arr, BUFF_SIZE)) > 0)
	{
		new_arr[i] = '\0';
		buf = ft_strjoin(old[fd], new_arr);
		ft_strdel(&old[fd]);
		old[fd] = buf;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(new_arr);
	if (i < 0)
		return (-1);
	return (ft_get_new_line(fd, line, old, i));
}

/*
static int	copy_until_break(t_buff *buff, char *chunk, size_t chunk_size,
		char **ptr)
{
	size_t	line_size;

	*ptr = ft_memchr(chunk, '\n', chunk_size);
	if (*ptr)
	{
		line_size = *ptr - chunk;
		CHECK0RET0(t_buff_append(buff, chunk, line_size));
		ft_bzero(chunk, line_size + 1);
	}
	else
	{
		CHECK0RET0(t_buff_append(buff, chunk, chunk_size));
		ft_bzero(chunk, chunk_size);
	}
	return (1);
}

static int	do_next_reads(int fd, t_buff *b, t_gnl_state *s)
{
	int		n;
	size_t	offset;

	while (1)
	{
		offset = s->cursor ? s->cursor - s->chunk + 1 : 0;
		CHECK0RET1(copy_until_break(b, s->chunk + offset,
				s->chunk_size - offset, &(s->cursor)));
		if (s->cursor)
			return (1);
		if (s->file_ended)
			return (0);
		CHECK1RET1((n = read(fd, s->chunk, BUFF_SIZE)));
		s->chunk_size = n;
		if (!n)
		{
			s->file_ended = 1;
			if (!GNL_LAST_EMPTY_LINE_BEHAVIOUR && !b->len)
				return (0);
			return (1);
		}
	}
}

t_gnl_state	*gnl_state_get(t_list **lst, const int fd)
{
	t_list		*e;
	t_gnl_state	*s;

	e = *lst;
	while (e)
	{
		if (((t_gnl_state *)(e->content))->fd == fd)
			return (e->content);
		e = e->next;
	}
	CHECK0RET0(s = malloc(sizeof(t_gnl_state)));
	ft_bzero(s, sizeof(t_gnl_state));
	s->fd = fd;
	if (!(e = ft_lstnew(s, sizeof(t_gnl_state))))
	{
		free(s);
		return (0);
	}
	ft_lstadd(lst, e);
	return (e->content);
}

void		gnl_state_remove(t_list **lst, const int fd)
{
	t_list	*ptr;
	t_list	*prev;
	t_list	*for_delete;

	prev = 0;
	ptr = *lst;
	while (ptr)
	{
		if (((t_gnl_state*)(ptr->content))->fd == fd)
		{
			if (!prev)
				*lst = ptr->next;
			else
				prev->next = ptr->next;
			for_delete = ptr;
			ptr = ptr->next;
			free(for_delete->content);
			free(for_delete);
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_list		*state_lst;
	t_gnl_state			*state;
	t_buff				buff;
	int					ret;

	CHECK0RET1(state = gnl_state_get(&state_lst, fd));
	CHECK0RET1(t_buff_init(&buff, 16));
	CHECK0RET1(line);
	ret = do_next_reads(fd, &buff, state);
	if (ret > 0)
	{
		buff.data[buff.len] = 0;
		*line = buff.data;
		return (1);
	}
	else
	{
		free(buff.data);
		gnl_state_remove(&state_lst, fd);
	}
	return (ret);

}
*/