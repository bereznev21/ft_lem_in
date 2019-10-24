/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:15:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/24 21:33:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_start
{
	int				num_rooms;
	int				num_leaks;
	char			*start;
	char			*rooms;
	char			*leaks;
	char			*end;
}					t_start;

typedef struct		s_map
{
	int				start;
	int				end;
	int				size;
	int				**matrix;
	int				**map_road;
	char			**ans;
}					t_map;

int		ft_read_map(t_start *start);
void	ft_crt_map_room(t_start *start, t_map *map);
void	ft_wrt_map_leaks(t_start *start, t_map *map);
void	ft_free_char(char **map, int width);
void	ft_zero_map(int **map, int width);

#endif
