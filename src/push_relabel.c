#include "lem_in.h"
# include "libft/includes/libft.h"
#include <limits.h>

static void push(t_pr_state *s, int u, int v)
{
	int send;

	send = s->cap->data[u][v] - s->flow->data[u][v];
	send = send > s->excess[u] ? s->excess[u] : send;
	s->flow->data[u][v] += send;
	s->flow->data[v][u] -= send;
	s->excess[u] -= send;
	s->excess[v] += send;
}

static void relabel(t_pr_state *s, int u)
{
	int v;
	int min_height;

	min_height = INT_MAX;
	for (v = 0; v < s->cap->n; v++)
	{
		if (s->cap->data[u][v] - s->flow->data[u][v] > 0)
		{
			min_height = min_height > s->height[v] ? s->height[v] : min_height;
			s->height[u] = min_height + 1;
		}
	}
	s->seen[u] = 0;
}

static void discharge(t_pr_state *s, int u)
{
	int v;

	while (s->excess[u] > 0)
	{
		if (s->seen[u] < s->cap->n)
		{
			v = s->seen[u];
			if ((s->cap->data[u][v] - s->flow->data[u][v] > 0) &&
				(s->height[u] > s->height[v]))
				push(s, u, v);
			else
				s->seen[u] += 1;
		}
		else
			relabel(s, u);
	}
}

void t_pr_init(t_pr_state *s, int size, int src, int dst)
{
	int i;
	int j;

	s->excess = ft_memalloc(size*sizeof(int));
	s->height = ft_memalloc(size*sizeof(int));
	s->seen = ft_memalloc(size*sizeof(int));
	s->list = ft_memalloc(size*sizeof(int));
	for (i = 0, j = 0; i < size; i++)
		if ((i != src) && (i != dst))
			s->list[j++] = i;
	s->height[src] = size;
	s->excess[src] = INT_MAX;
	for (i = 0; i < s->cap->n; ++i)
		push(s, src, i);
}

static void move_to_front(int i, int *a)
{
	int temp = a[i];
	int n;
	for (n = i; n > 0; n--)
		a[n] = a[n - 1];
	a[0] = temp;

}

t_matrix push_relabel(t_matrix *cap, int src, int dst)
{
	t_matrix flow;
	t_pr_state s;
	int u;
	int p;
	int old_height;

	s.cap = cap;
	s.flow = &flow;
	t_matrix_init(&flow, cap->n, cap->n);
	t_pr_init(&s, cap->n, src, dst);

	p = 0;
	while (p < cap->n - 2)
	{
		u = s.list[p];
		old_height = s.height[u];
		discharge(&s, u);
		if (s.height[u] > old_height)
		{
			move_to_front(p, s.list);
			p = 0;
		}
		else
			p += 1;
	}
	//todo: free;
	return (flow);
}
