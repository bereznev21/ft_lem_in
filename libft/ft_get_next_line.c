/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:29:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/13 19:50:44 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int	ft_get_new_line(const int fd, char **line, char **old, int i)
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
			return (ft_get_next_line(fd, line));
		*line = ft_strdup(old[fd]);
		ft_strdel(&old[fd]);
	}
	return (1);
}

int			ft_get_next_line(const int fd, char **line)
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
