/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:34:24 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/18 17:06:01 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void		t_paths_init(t_paths *pp, t_startend se, int size)
{
	pp->paths = ft_memalloc(sizeof(int*) * 256);
	pp->se = se;
	pp->size = size;
	pp->paths_rev = 0;
}

void		print_path(int *path, int size, t_startend se)
{
	int i;

	(void)size;
	i = se.start;
	printf("%d", i);
	while (i != se.end)
	{
		printf("->%d", (i = path[i]));
	}
	printf("\n");
	printf("\n");
}

void		t_paths_print(t_paths pp)
{
	int i;

	i = -1;
	while (pp.paths[++i])
		print_path(pp.paths[i], pp.size, pp.se);
}

void		t_paths_init_rev(t_paths *pp)
{
	int i;
	int k;

	if (pp->paths_rev)
		free(pp->paths_rev);
	pp->paths_rev = malloc(sizeof(int *) * (ft_len((void **)pp->paths) + 1));
	i = -1;
	while (pp->paths[++i])
	{
		pp->paths_rev[i] = malloc(sizeof(int) * pp->size);
		k = pp->se.start;
		while (k != pp->se.end)
		{
			pp->paths_rev[i][pp->paths[i][k]] = k;
			k = pp->paths[i][k];
		}
	}
	pp->paths_rev[i] = 0;
}

t_paths		t_paths_copy(t_paths pp)
{
	t_paths	ret;
	int		i;

	t_paths_init(&ret, pp.se, pp.size);
	i = -1;
	while (pp.paths[++i])
		ret.paths[i] = ft_memdup(pp.paths[i], sizeof(int) * pp.size);
	return (ret);
}

void		t_paths_del(t_paths *pp)
{
	int i;

	i = -1;
	while (pp->paths[++i])
		free(pp->paths[i]);
	free(pp->paths);
	if (pp->paths_rev)
	{
		i = -1;
		while (pp->paths_rev[++i])
			free(pp->paths_rev[i]);
		free(pp->paths_rev);
	}
}
