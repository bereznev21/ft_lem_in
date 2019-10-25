/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:06:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/25 23:30:44 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
//#include "libft.h"
# include "libft/includes/libft.h"

/*
int		ft_read_map1(t_start *start, int fd, char *line)
{
	if (ft_strstr(line, "##end"))
	{
		free(line);
		ft_get_next_line(fd, &line);
		start->end = ft_atoi(line);
		free(line);
		while (1)
		{
			if (ft_get_next_line(fd, &line) == 0)
				return (1);
			else if (ft_strstr(line, "#"))
				free(line);
			else
			{
				start->leaks = ft_strjoin_right(start->leaks, " ");
				start->leaks = ft_strjoin_right(start->leaks, line);
				free(line);
			}
		}
	}
	return (0);
}
*/
/*
int		ft_read_map(t_start *start, int fd)
{
	char	*line;

	ft_get_next_line(fd, &line);
	if (ft_strstr(line, "##start"))
	{
		free(line);
		ft_get_next_line(fd, &line);
		start->start = ft_atoi(line);
		start->rooms = ft_strjoin_right(start->rooms, line);
		free(line);
		while (ft_get_next_line(fd, &line) > 0)
		{
			if (ft_strstr(line, "##end"))
				break ;
			else if (ft_strstr(line, "#"))
				free(line);
			else
			{
				start->rooms = ft_strjoin_right(start->rooms, " ");
				start->rooms = ft_strjoin_right(start->rooms, line);
				free(line);
			}
		}
	}
	else
		return (0);
		//strerrror
	return (ft_read_map1(start, fd, line));
}
*/

int		ft_read_map(t_start *start, int fd)
{
	char	*line;
	int		check_start;
	int		check_end;

	check_start = 0;
	check_end = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0)
			check_start = (check_start == 0) ? 1 : 0;
		else if (ft_strcmp(line, "##end") == 0 && check_start == 1)
			check_end = (check_end == 0) ? 1 : 0;
		else if (line[0] != '#')
		{
			if (check_start == 1 && check_end == 0)
			{
				start->rooms = ft_strjoin_right(start->rooms, " ");
				start->rooms = ft_strjoin_right(start->rooms, line);
			}
			else if (check_start == 1 && check_end == 1)
			{
				if (start->end != -1)
				{
					start->leaks = ft_strjoin_right(start->leaks, " ");
					start->leaks = ft_strjoin_right(start->leaks, line);
				}
				else
					start->end = line[0];
			}
		}
		free(line);
	}
	if (!(check_start == 1 && check_end == 1))
		return (0);
	//strerror;
	return (1);
}
