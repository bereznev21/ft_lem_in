#ifndef LEM_IN_H
# define LEM_IN_H

typedef	struct
{
	int			n;
	int			**data;
} 				t_matrix;

typedef struct
{
	int				*excess;
	int				*height;
	int				*list;
	int				*seen;
	t_matrix		*cap;
	t_matrix		*flow;
}					t_pr_state;

typedef struct		s_start
{
	int				num_rooms;
	int				num_leaks;
	int				start;
	int				end;
	char			*rooms;
	char			*leaks;
	char			**names_rooms_table;
}					t_start;

typedef struct		s_map
{
	int				start;
	int				end;
	t_matrix		matrix;
	int				**map_road;
}					t_map;

void		t_matrix_init(t_matrix *m, int n);
t_matrix	push_relabel(t_matrix *cap, int src, int dst);
void		t_matrix_set(t_matrix *m, int i, int j);
int			ft_read_map(t_start *start, int fd);
void		ft_crt_map_room(t_start *start);
void		ft_wrt_map_leaks(t_start *start, t_matrix *leaks);
void		t_matrix_print(t_matrix *m);

#endif