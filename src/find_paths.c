/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:07:41 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/26 18:32:11 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include "libft/includes/libft.h"

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

void	ft_put_endl(int *nodes, int i)
{
	int	n;

	n = 0;
	while (nodes[n] > -1)
		n++;
	nodes[n] = i;
}

int		ft_check_node(int *nodes, int num)
{
	int	i;

	i = 0;
	while (i < num)
		if (nodes[i] != 0)
			return (0);
	return (1);
}

int		ft_get_node(int *nodes, int num)
{
	int		node;
	int		i;
	int		*new_nodes;

	i = -1;
	node = nodes[0];
	new_nodes = (int*)malloc(sizeof(int) * num);
	ft_bminus(new_nodes, num);
	while (++i < num)
	{
		new_nodes[i] = nodes[i + 1];
		//printf("%d\n", new_nodes[i]);
	}
	return (node);
}

void	find_paths(t_matrix *mat, int start, int end)
{
//	int		i;
	int		node;
	int		*nodes;
	int		num;

	nodes = (int*)malloc(sizeof(int) * mat->n);
	ft_bminus(nodes, mat->n);
	ft_put_endl(nodes, start);
	//printf("%d\n", nodes[0]);
	//printf("%d\n", start);
	//while (ft_check_node(nodes, mat->n) == 1)
	{
		num = mat->n;
		node = ft_get_node(nodes, --num);
		printf("%d\n", node);
	}
	printf("%d %d %d\n", mat->n, start, end);
}
