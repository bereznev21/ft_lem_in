/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 16:58:16 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void	ft_bminus(int **s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		(*s)[i] = DISJ;
}

int	ft_restore_patch(t_matrix *least_patch, t_matrix *paths_map, int start, int end)
{
	int	i;
	int	ends;

	t_matrix_init_zero(least_patch, paths_map->m, paths_map->n);
	ends = end;
	while (ends != start)
	{
		i = -1;
		while (++i < paths_map->n)
		{
			if (paths_map->data[i][ends] == 1)
			{
				least_patch->data[i][ends] = 1;
				ends = i;
				break;
			}
		}
		if (i == paths_map->m)
			return (0);
	}
	//t_matrix_print(least_patch);
	ft_free_matrix(paths_map);
	return (1);
}

int		find_paths(t_matrix *aj, t_matrix *paths_map, int start, int end)
{
	t_queue	*q;
	int		*used;
	int		node;
	int		i;

	i = 0;
	q = (t_queue*)malloc(sizeof(t_queue));
	q->data = DISJ;
	q->next = NULL;
	used = (int*)malloc(sizeof(int) * aj->n);
	ft_bminus(&used, aj->n);
	ft_q_push(&q, start);
	used[start] = 1;
	while ((ft_q_empty(q)))
	{
		node = ft_q_front(q);
		if (node == -1 || node == DISJ)
			break ;
		ft_q_pop(&q);
		i = 0;
		if (node == end)
			break ;
		while (i < aj->m)
		{
			if(used[i] == DISJ && aj->data[node][i] != DISJ)
			{
				//printf("%d %d\n", node, i);
				//if (node >= 0 || )
				ft_q_push(&q, i);
				paths_map->data[node][i] = 1;
				used[i] = 1;
				//printf("%d\n", node);
			}
			i++;
		}
	}
	ft_free_q(&q);
	free(used);
	return (1);
}

int find_path(t_matrix *aj, t_matrix *paths, int start, int end)
{
	t_matrix ret;

	t_matrix_init(&ret, aj->m, aj->n);
	find_paths(aj, &ret, start, end);
	return ft_restore_patch(paths, &ret, start, end);
}
