/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:06:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/22 21:06:06 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_read_map1(t_start *start, char *line)
{
	if (ft_strstr(line, "##end"))
	{
		free(line);
		ft_get_next_line(0, &line);
		start->end = ft_strdup(line);
		free(line);
		while (1)
		{
			if (ft_get_next_line(0, &line) == 0)
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

int		ft_read_map(t_start *start)
{
	char	*line;
	int		i;

	i = 0;
	ft_get_next_line(0, &line);
	if (ft_strstr(line, "##start"))
	{
		free(line);
		ft_get_next_line(0, &line);
		start->start = ft_strdup(line);
		free(line);
		while (1)
		{
			if (ft_get_next_line(0, &line) == 0)
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
	return (ft_read_map1(start, line));
}
