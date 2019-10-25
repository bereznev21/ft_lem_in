/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:06:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/25 15:37:51 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
//#include "libft.h"
# include "libft/includes/libft.h"

int		ft_read_map1(t_start *start, int fd, char *line)
{
	if (ft_strstr(line, "##end"))
	{
		free(line);
		ft_get_next_line(fd, &line);
		//ft_srch_nbr(start, line);
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
		while (1)
		{
			if (ft_get_next_line(fd, &line) == 0)
				return (0);
			else if (ft_strstr(line, "##end"))
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
	{
		return (0);
	}
	return (ft_read_map1(start, fd, line));
}
