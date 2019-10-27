/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/27 19:06:49 by rpoetess         ###   ########.fr       */
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


int		**find_paths(t_matrix *mat, int start, int end)
{
	int		node;
	int		num;
	int		*nodes;
	int		*stack;
	int		**paths;
	int		j;

	paths = NULL;
	(void)end;
	nodes = (int*)malloc(sizeof(int) * mat->n);
	stack = (int*)malloc(sizeof(int) * mat->n);
	paths = ft_crt_map(paths, mat->n);
	ft_bminus(&nodes, mat->n);
	ft_bminus(&stack, mat->n);
	ft_push(&stack, start);
	//printf("%d\n",  [0]);
	//printf("%d\n", start);
	num = mat->n;
	while (ft_check_node(stack, num) == 1)
	{
		num = mat->n;
		node = ft_get_node(&stack, --num);
		//if (node < 0)
		//	continue;
		if (nodes[node] == 2)
			continue;
		nodes[node] = 2;
		j = num;
		while (j >= 0)
		{
			if (mat->data[node][j] == 1 && nodes[j] != 2)
			{
				/*ft_putchar('|');
				ft_putnbr(node);
				ft_putchar('-');
				ft_putnbr(j);
				ft_putchar('|');*/
				paths[node][j] = 1;
				paths[j][node] = -1;
				ft_push(&stack, j);
				nodes[j] = 1;
			}
			j--;
		}
		//ft_putnbr(node);
		if (node == end)
			continue;
	}
	//ft_print_matrix(paths, mat->n);
	//printf("\n%d %d %d\n", mat->n, start, end);
	free(stack);
	free(nodes);
	return (paths);
}
