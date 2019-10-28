#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>

typedef struct	s_matrix
{
	int m;
	int n;
	int **data;
}				t_matrix;

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
} 				t_room;

typedef struct	s_pr_state
{
	int			*excess;
	int			*height;
	int			*list;
	int			*seen;
	t_matrix	*cap;
	t_matrix	*flow;
}				t_pr_state;

typedef struct	s_start
{
	int		num_rooms;
	int		num_leaks;
	int		start;
	int		end;
	char	*rooms;
	char	*leaks;
	char	**names_rooms_table;
}				t_start;

typedef struct s_map
{
	int			start;
	int			end;
	t_matrix	matrix;
	int			**map_road;
}				t_map;

typedef struct	s_array
{
	size_t item_size;
	int count;
	int size;
	void *data;
}				t_array;

typedef struct	s_lem_in
{
	int start;
	int end;
	int ants;
	t_array rooms;
}				t_lem_in;

void		t_matrix_init(t_matrix *mat, int m, int n);
void		t_matrix_init_identity(t_matrix *mat, int n);
t_matrix	t_matrix_mul(t_matrix *a, t_matrix *b);
void		t_matrix_t(t_matrix *a);
t_matrix	expand_junctions(t_matrix *aj);
t_matrix	push_relabel(t_matrix *cap, int src, int dst);
void		t_matrix_set(t_matrix *m, int i, int j, int v);
int			ft_read_map(t_start *start, int fd);
void		ft_crt_map_room(t_start *start);
void		ft_wrt_map_leaks(t_start *start, t_matrix *leaks);
void		t_matrix_print_no_headers(t_matrix *m);
void 		ft_crt_names_rooms_table(t_start *start, char **res, int i);
void		t_matrix_print(t_matrix *m);
void		t_matrix_del(t_matrix *m);
t_matrix	lem_in_read(int fd, t_lem_in *lem_in);
t_matrix	find_paths(t_matrix* aj, int start, int end);
int			**select_paths(int **paths, int size);
int			**find_paths_mock(t_matrix *aj, int start, int end);
void		lem_in_output(int **paths, int num_paths, int lems);
void 		ft_print_matrix(int **map, int width);

void		t_array_init(t_array *a, size_t item_size);
void		*t_array_get(t_array *a, int i);
void		*t_array_push(t_array *a, void *content);

#endif
