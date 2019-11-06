/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/06 15:01:53 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

/*
void	ft_bminus(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buffer[i] = -1;
		i++;
	}
}
*/

void	ft_bminus(int **s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		(*s)[i] = DISJ;
}

void	ft_push(int **nodes, int i)
{
	int	n;

	n = 0;
	while ((*nodes)[n] > DISJ)
		n++;
	(*nodes)[n] = i;
	//ft_putnbr((*nodes)[n]);
	//ft_putchar('\n');
}

int		ft_check_node(int *nodes, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		//ft_putnbr(nodes[i]);
		//ft_putchar('\n');
		if (nodes[i] != DISJ)
			return (1);
	}
	return (0);
}

int		ft_get_node(int **stack, int num)
{
	int		node;
	int		i;
	int		*new_nodes;

	(void)i;
	i = 0;
	node = *stack[0];
	new_nodes = (int*)malloc(sizeof(int) * num);
	ft_bminus(&new_nodes, num);
	ft_memmove(new_nodes, *stack + 1, num);
	free(*stack);
	*stack = new_nodes;
	//ft_putnbr(**stack);
	//ft_putchar('\n');
	return (node);
}
/*
int		**ft_crt_map(int **map, int n)
{
	int	i;

	i = -1;
	map = (int**)malloc(sizeof(int *) * n);
	while (++i < n)
	{
		map[i] = malloc(sizeof(int) * n);
		ft_bzero(map[i], n * sizeof(int));
	}
	return(map);
}
*/
/*
t_matrix	find_paths(t_matrix *aj, int start, int end) // DFS
{
	int			node;
	int			num;
	int			*nodes;
	int			*stack;
	t_matrix	paths_map;
	int			j;

	nodes = (int*)malloc(sizeof(int) * aj->n);
	stack = (int*)malloc(sizeof(int) * aj->n);
	t_matrix_init(&paths_map, aj->n, aj->n);
	ft_bminus(&nodes, aj->n);
	ft_bminus(&stack, aj->n);
	ft_push(&stack, start);
	num = aj->n;
	while (ft_check_node(stack, num) == 1)
	{
		num = aj->n;
		node = ft_get_node(&stack, --num);
		if (node == end)
			continue;
		if (nodes[node] == 2)
			continue;
		nodes[node] = 2;
		j = num;
		while (j >= 0)
		{
			if (aj->data[node][j] == 1 && nodes[j] != 2)
			{
				paths_map.data[node][j] = 1;
				paths_map.data[j][node] = -1;
				ft_push(&stack, j);
				num++;
				nodes[j] = 1;
			}
			j--;
		}
	}
	free(stack);
	free(nodes);
	return (paths_map);
}
*/
/*
int		find_paths(t_matrix *aj, t_matrix *paths_map, int start, int end) // BFS
{
	int			node;
	int			num;
	int			*nodes;
	int			*stack;
	int			j;

	(void)end;
	nodes = (int*)malloc(sizeof(int) * aj->n);
	stack = (int*)malloc(sizeof(int) * aj->n);
	ft_bminus(&nodes, aj->n);
	ft_bminus(&stack, aj->n);
	ft_push(&stack, start);
	num = aj->n;
	while (ft_check_node(stack, num) == 1)
	{
		num = aj->n;
		node = ft_get_node(&stack, --num);
		if (node == end)
			continue;
		nodes[node] = 2;
		j = 0;
		while (j < num)
		{
			if (aj->data[node][j] == 1 && nodes[j] == -1)
			{
				paths_map->data[node][j] = 1;
				paths_map->data[j][node] = -1;
				ft_push(&stack, j);
				num++;
				nodes[j] = 1;
			}
			j++;
		}
	}
	free(stack);
	free(nodes);
	//return (paths_map);
	return (0);
}
*/
int	ft_restore_patch(t_matrix *least_patch, t_matrix paths_map, int start, int end)
{
	int	i;
	int	ends;

	t_matrix_init_zero(least_patch, paths_map.m, paths_map.n);
	ends = end;
	while (ends != start)
	{
		i = 0;
		while (i < paths_map.n)
		{
			if (paths_map.data[i][ends] == 1)
			{
				//if (ends != end)
				{
					//printf("%d ", ends);
					least_patch->data[i][ends] = 1;
				}
				ends = i;
				break;
			}
			i++;
		}
		//printf("\n");
		if (i == paths_map.m)
			return (0);
	}
	return (1);
}

/*
int	find_paths(t_matrix *aj, t_matrix *paths_map, int start, int end) // Dijkstra
{
	int			node;
	int			num;
	int			*nodes;
	int			*stack;
	int			j;

	(void)end;
	nodes = (int*)malloc(sizeof(int) * aj->n);
	stack = (int*)malloc(sizeof(int) * aj->n);
	t_matrix_init(paths_map, aj->n, aj->n);
	ft_bminus(&nodes, aj->n);
	ft_bminus(&stack, aj->n);
	ft_push(&stack, start);
	num = aj->n;
	//printf("%d\n", num);
	while (ft_check_node(stack, num) == 1)
	{
		num = aj->n;
		node = ft_get_node(&stack, --num);
	//	if (node <= 0)
	//		continue ;
	//	printf("%d\n", node);
		if (node == end)
			return (1);
		nodes[node] = 2;
		j = 0;
		while (j < aj->n)
		{
			if (nodes[j] == DISJ && aj->data[node][j] != DISJ)
			{
				ft_push(&stack, j);
				num++;
				paths_map->data[node][j] = 1;
				//paths_map.data[j][node] = -1;
				nodes[j] = 1;
				//if (node == end)
				//	break ;
			}
			j++;
		}
	}
	free(stack);
	free(nodes);
	return (0);
}
*/

void	ft_q_push(t_queue **q, int node)
{
	t_queue *tmp;
	t_queue *list;

	tmp = *q;
	list = (t_queue*)malloc(sizeof(t_queue));
	list->data = node;
	list->next = NULL;
	if (list)
	{
		while (tmp->next)
		{
			//q->next->previous = q; 
			tmp = tmp->next;
		}
		tmp->next = list;
	}
}

int		ft_q_empty(t_queue *q)
{
	int i;

	i = 0;
	if (q && q->data >= 0)
		return (1);
	return (0);
}

int		ft_q_front(t_queue *q)
{
	if (q->data >= 0)
		return (q->data);
	return (-1);
}

void	ft_q_pop(t_queue **q)
{
	t_queue *tmp;

	tmp = (*q)->next;
	//free(q);
	*q = tmp;
}

int		find_paths(t_matrix *aj, t_matrix *paths_map, int start, int end)
{
	t_queue	*q;
	int		*used;
	int		node;
	int		i;

	i = 0;
	(void)end;
	q = (t_queue*)malloc(sizeof(t_queue));
	q->next = NULL;
	used = (int*)malloc(sizeof(int) * aj->n);
	ft_bminus(&used, aj->n);
	ft_q_push(&q, start);
	used[start] = 1;
	while ((ft_q_empty(q)))
	{
		node = ft_q_front(q);
		ft_q_pop(&q);
		i = 0;
		if (node == end)
			break ;
		while (i < aj->m)
		{
			if(used[i] == DISJ && aj->data[node][i] != DISJ)
			{
				//printf("%d %d\n", node, i);
				ft_q_push(&q, i);
				paths_map->data[node][i] = 1;
				used[i] = 1;
				//printf("%d\n", node);
			}
			i++;
		}
	}
	return (1);
}
