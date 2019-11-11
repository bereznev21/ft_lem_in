/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:52 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/11 18:15:35 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_arr_char(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_arr_int(int **str, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(str[i++]);
	free(str);
}

void	ft_free_matrix(t_matrix *matrix)
{
	int i;

	i = -1;
	while (++i < matrix->m)
		free(matrix->data[i]);
	free(matrix->data);
//	free(matrix);
}

void	ft_free_q(t_queue **q)
{
	t_queue	*tmp;
	t_queue	*list;

	list = *q;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = 0;
		free(list);
		list = tmp;
	}
	free(list);
}

void	ft_free_lem_in(t_lem_in *lem_in)
{
	(void)lem_in;
}

void	ft_free(t_lem_in *lem_in, t_matrix *aj, t_matrix *paths)
{
	(void)lem_in;
	(void)aj;
	(void)paths;
	//ft_free_lem_in(&lem_in);
	ft_free_matrix(aj);
}
