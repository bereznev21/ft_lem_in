/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/28 19:19:45 by rpoetess         ###   ########.fr       */
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
		(*s)[i] = -1;
}

void	ft_push(int **nodes, int i)
{
	int	n;

	n = 0;
	while ((*nodes)[n] > -1)
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
		if (nodes[i] != -1)
			return (1);
	}
	return (0);
}

int		ft_get_node(int **stack, int num)
{
	int		node;
	int		i;
	int		*new_nodes;

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

t_matrix	find_paths(t_matrix *aj, int start, int end) // BFS
{
	int			node;
	int			num;
	int			*nodes;
	int			*stack;
	t_matrix	paths;
	int			j;

	(void)end;
	nodes = (int*)malloc(sizeof(int) * aj->n);
	stack = (int*)malloc(sizeof(int) * aj->n);
	t_matrix_init(&paths, aj->n, aj->n);
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
				paths.data[node][j] = 1;
				paths.data[j][node] = -1;
				ft_push(&stack, j);
				num++;
				nodes[j] = 1;
			}
			j--;
		}
		//ft_putnbr(node);
	//	if (node == end)
	//		continue;
	}
	//ft_print_matrix(paths, aj->n);
	//printf("\n%d %d %d\n", aj->n, start, end);
	free(stack);
	free(nodes);
	return (paths);
}


/*
int		**find_paths(t_matrix *mat, int start, int end) // Dijkstra
{
	int		node;
	int		num;
	int		*nodes;
	int		*stack;
	int		**paths;
	int		j;
	int		start1;
	int		end1;

	start1 = 0;
	end1 = 0;
	j = 0;
	paths = NULL;
	(void)end;
	nodes = (int*)malloc(sizeof(int) * mat->n);
	stack = (int*)malloc(sizeof(int) * mat->n);
	paths = ft_crt_map(paths, mat->n);
	ft_bminus(&nodes, mat->n);
	ft_bminus(&stack, mat->n);
	ft_push(&stack, start);
	num = mat->n;
	while (ft_check_node(stack, num) == 1)
	{
		num = 0;
		node = ft_get_node(&stack, --num);
		nodes[node] = 2;
		while (num < mat->n)
		{
			if (mat->data[node][j] == 1 && nodes[j] == -1)
			{
				//paths[node][j] = 1;
				//paths[j][node] = -1;
				ft_push(&stack, j);
				nodes[j] = 1;
				start1 = node;
				end1 = j;
				ft_push()
				if (node == mat->n)
					break ;
			}
			num++;
		}
		//printf("%d\n", node);
		ft_putnbr(node);
		ft_putchar('\n');
	}
	return (paths);
}
*/