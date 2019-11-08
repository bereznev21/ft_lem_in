
#include "lem_in.h"

void	ft_q_push(t_queue **q, int node)
{
	t_queue *tmp;
	t_queue *list;

	tmp = *q;
	if (tmp->data != DISJ)
	{
		list = (t_queue*)malloc(sizeof(t_queue));
		list->data = node;
		list->next = NULL;
		if (list)
		{
			while (tmp && tmp->next)
				tmp = tmp->next;
			tmp->next = list;
		}
	}
	else
		(*q)->data = node;
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

	if ((*q)->next)
	{
		tmp = (*q)->next;
		//free(q);
		*q = tmp;
	}
	else
		(*q)->data = DISJ;
}