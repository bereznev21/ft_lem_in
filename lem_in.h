#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include <stdlib.h>

# define ULONG unsigned long
# define DISJ INT_MAX

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

typedef struct	s_array
{
	size_t item_size;
	int count;
	int size;
	void *data;
}				t_array;

typedef struct	s_collapse
{
	t_array a;
	t_matrix m;
	int size;
}				t_collapse;

typedef struct	s_lem_in
{
	int start;
	int end;
	int ants;
	t_array rooms;
}				t_lem_in;

typedef	struct 		s_queue
{
	int				data;
	struct s_queue	*next;
}					t_queue;

void		t_array_init(t_array *a, size_t item_size);
void		*t_array_get(t_array *a, int i);
void		*t_array_push(t_array *a, void *content);
void		t_array_del(t_array *a);

void		t_matrix_init(t_matrix *mat, int m, int n);
void		t_matrix_init_identity(t_matrix *mat, int n);
void 		t_matrix_init_zero(t_matrix *mat, int m, int n);
t_matrix	t_matrix_copy(t_matrix *m);
t_matrix	t_matrix_add(t_matrix *a, t_matrix *b);
t_matrix	t_matrix_mul(t_matrix *a, t_matrix *b);
void		t_matrix_t(t_matrix *a);
void		t_matrix_duplicate_row(t_matrix *aj, int k, int m);
void		t_matrix_duplicate_col(t_matrix *aj, int k, int m);
void		t_matrix_duplicate_node(t_matrix *aj, int k, int m);
void		t_matrix_print_no_headers(t_matrix *m);
void		t_matrix_print(t_matrix *m);
void		t_matrix_del(t_matrix *m);

t_matrix	expand_junctions(t_matrix *aj);
t_matrix	push_relabel(t_matrix *cap, int src, int dst);
void		t_matrix_set(t_matrix *m, int i, int j, int v);
t_matrix	lem_in_read(int fd, t_lem_in *lem_in);
int			t_restore_patch(t_matrix *least_patch, t_matrix paths_map, int start, int end);
ULONG		select_paths(t_array *arr);
int			**find_paths_mock(t_matrix *aj, int start, int end);
void		lem_in_output(t_matrix paths, t_matrix aj, t_lem_in lem_in);
int			ft_srch_min(int *len_table);

void		t_collapse_add(t_collapse *c, int k);
void		t_collapse_do(t_collapse *c, t_matrix *paths);
void		t_collapse_init(t_collapse *c, int size);

t_matrix	ft_trnsfr_paths(t_matrix paths_map, int start, int end);
t_array		path_matrix_to_bit_masks(t_matrix *aj, int start, int end);
void		ft_put_end(int **roads, int end);
void		ft_src_roads(t_matrix *ans, t_matrix *map, int k);
void		ft_src_roads1(t_matrix	*res, t_matrix *map, int frst_room, int num_room);
void		ft_bminus(int **s, size_t n);
int			suurballe(t_matrix *aj, t_matrix *all_paths, int start, int end);
int			find_shortest_path(t_matrix *aj, t_matrix *path, int start, int end);
int			bf_shortest_path(t_matrix *aj, t_matrix *paths_map, int stat, int end);
int			find_paths(t_matrix *aj, t_matrix *paths_map, int start, int end);
int			find_path(t_matrix *aj, t_matrix *paths, int start, int end);

void		ft_free(t_lem_in *lem_in, t_matrix *aj, t_matrix *paths);
void		ft_free_matrix(t_matrix *matrix);
void		ft_free_q(t_queue **q);
void		ft_free_arr_int(int **str, int width);

void 		ft_print_matrix(int **map, int width);
void		ft_print_arr(int *lems_in_rooms, int n);
void		ft_print_lems(int *lems_in_rooms, t_matrix paths_table, t_lem_in lem_in, int max_path);

void		ft_move_leams_in_path(t_matrix *condition_of_ants, t_matrix paths_table, int k);
void		ft_crt_len_table(t_matrix paths, t_lem_in lem_in, t_matrix *paths_table, int **len_table);

void		ft_q_push(t_queue **q, int node);
int			ft_q_empty(t_queue *q);
int			ft_q_front(t_queue *q);
void		ft_q_pop(t_queue **q);

#endif