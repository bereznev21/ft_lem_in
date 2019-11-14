/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/14 15:41:09 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "lem_in.h"

void	ft_bminus(int **s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		(*s)[i] = DISJ;
}

int		ft_restore_patch(t_matrix *least_patch,
			t_matrix *paths_map, t_startend se)
{
	int	i;
	int	ends;

	t_matrix_init_zero(least_patch, paths_map->m, paths_map->n);
	ends = se.end;
	while (ends != se.start)
	{
		i = -1;
		while (++i < paths_map->n)
		{
			if (paths_map->data[i][ends] == 1)
			{
				least_patch->data[i][ends] = 1;
				ends = i;
				break ;
			}
		}
		if (i == paths_map->m)
		{
			t_matrix_del(paths_map);
			return (0);
		}
	}
	t_matrix_del(paths_map);
	return (1);
}

void	ft_go_queue(t_queue **q, t_used *used, t_matrix *paths_map, t_matrix *aj)
{
	int	node;
	int	i;

	while ((ft_q_empty(*q)))
	{
		node = ft_q_front(*q);
		if (node == -1 || node == DISJ)
			break ;
		ft_q_pop(q);
		i = -1;
		if (node == used->se.end)
			break ;
		while (++i < paths_map->m)
		{
			if (used->data[i] == DISJ && aj->data[node][i] != DISJ)
			{
				ft_q_push(q, i);
				paths_map->data[node][i] = 1;
				used->data[i] = 1;
			}
		}
	}
}

int		find_paths(t_matrix *aj, t_matrix *paths_map, t_startend se)
{
	t_queue	*q;
	t_used	*used;
//	int		*used;

	q = (t_queue*)malloc(sizeof(t_queue));
	q->data = DISJ;
	q->next = NULL;
	used = (t_used*)malloc(sizeof(t_used));
	used->data = (int*)malloc(sizeof(int) * aj->n);
	used->se.start = se.start;
	used->se.end = se.end;
	ft_bminus(&used->data, aj->n);
	ft_q_push(&q, se.start);
	used->data[se.start] = 1;
	ft_go_queue(&q, used, paths_map, aj);
	ft_free_q(&q);
//	free(used);
	return (1);
}

int		find_path(t_matrix *aj, t_matrix *paths, t_startend se)
{
	t_matrix ret;

	t_matrix_init(&ret, aj->m, aj->n);
	find_paths(aj, &ret, se);
	return (ft_restore_patch(paths, &ret, se));
}
