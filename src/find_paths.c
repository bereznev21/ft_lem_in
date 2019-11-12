/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/11 17:53:06 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdio.h>

void	ft_bminus(int **s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		(*s)[i] = DISJ;
}

int	ft_restore_patch(t_matrix *least_patch, t_matrix *paths_map, t_startend se)
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
	//t_matrix_print(least_patch);
	t_matrix_del(paths_map);
	return (1);
}

int		find_paths(t_matrix *aj, t_matrix *paths_map, t_startend se)
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
	ft_q_push(&q, se.start);
	used[se.start] = 1;
	while ((ft_q_empty(q)))
	{
		node = ft_q_front(q);
		if (node == -1 || node == DISJ)
			break ;
		ft_q_pop(&q);
		i = 0;
		if (node == se.end)
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

int find_path(t_matrix *aj, t_matrix *paths, t_startend se)
{
	t_matrix ret;

	t_matrix_init(&ret, aj->m, aj->n);
	find_paths(aj, &ret, se);
	return ft_restore_patch(paths, &ret, se);
}
