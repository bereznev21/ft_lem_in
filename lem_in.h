/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:35:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/16 17:49:52 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define ULONG unsigned long
# define UINT unsigned int
# define DISJ INT_MAX
# define MAT_ALLOC_STEP 512
# define FLAG_PRINT_INPUT 1
# define FLAG_DEBUG 2

typedef struct		s_startend
{
	int				start;
	int				end;
}					t_startend;

typedef struct		s_matrix
{
	int				m_alloc;
	int				n_alloc;
	int				m;
	int				n;
	int				**data;
}					t_matrix;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

typedef struct		s_array
{
	size_t			item_size;
	int				count;
	int				size;
	void			*data;
}					t_array;

typedef struct		s_collapse
{
	t_array			a;
	t_matrix		m;
	int				size;
}					t_collapse;

typedef struct		s_lem_in
{
	t_startend		se;
	int				ants;
	t_array			rooms;
	UINT			flags;
}					t_lem_in;

typedef	struct		s_queue
{
	int				data;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_paths
{
	int				**paths;
	int				size;
	t_startend		se;
	int				**paths_rev;
}					t_paths;

typedef	struct		s_used
{
	int				*data;
	t_startend		se;
}					t_used;

void		t_array_init(t_array *a, size_t item_size);
void		*t_array_get(t_array *a, int i);
void		*t_array_push(t_array *a, void *content);
void		t_array_del(t_array *a);
void		ft_init_arr_1(int **arr, int len);
int			**ft_init_arr_2_zero(int m, int n);

void		t_matrix_init(t_matrix *mat, int m, int n);
void		t_matrix_init_identity(t_matrix *mat, int n);
void		t_matrix_init_zero(t_matrix *mat, int m, int n);
t_matrix	t_matrix_copy(t_matrix *m);
t_matrix	t_matrix_add(t_matrix *a, t_matrix *b);
t_matrix	t_matrix_mul(t_matrix *a, t_matrix *b);
void		t_matrix_t(t_matrix *a);
void		t_matrix_duplicate_row(t_matrix *aj, int k, int m);
void		t_matrix_duplicate_col(t_matrix *aj, int k, int m);
void		t_matrix_print_no_headers(t_matrix *m);
void		t_matrix_print(t_matrix *m);
void		t_matrix_del(t_matrix *m);
int			round_up(int a);

void		t_matrix_set(t_matrix *m, int i, int j, int v);
t_matrix	lem_in_read(int fd, t_lem_in *lem_in);
void		lem_in_output(t_paths paths, t_matrix aj, t_lem_in lem_in);
int			ft_srch_max_paths_in_rooms(int *len_table, int len);

void		t_collapse_add(t_collapse *c, int k);
void		t_collapse_do(t_collapse *c, int *path, int size, t_startend se);
void		t_collapse_init(t_collapse *c, int size);

t_matrix	ft_trnsfr_paths(t_matrix paths_map, int start, int end);
t_array		path_matrix_to_bit_masks(t_matrix *aj, int start, int end);
void		ft_put_end(int **roads, int end);
void		ft_bminus(int **s, size_t n);
int			suurballe_next(t_matrix aj, t_paths *pp);
void		remove_sym(t_paths pp);

void		print_path(int *path, int size, t_startend se);
void		t_paths_print(t_paths pp);
void		t_paths_init(t_paths *pp, t_startend se, int size);
void		t_paths_init_rev(t_paths *pp);

int			find_paths(t_matrix *aj, t_matrix *paths_map, t_startend se);
int			*find_path(t_matrix *aj, t_startend se);
int			path_step(t_matrix *path, int k);
void		ft_free(t_lem_in *lem_in, t_matrix *aj, t_matrix *paths);
void		ft_free_matrix(t_matrix *matrix);
void		ft_free_q(t_queue **q);
void		ft_free_arr_int(int **str, int width);
void		ft_free_arr_char(char **map);

void		ft_print_ans(int num_len, char *room_name);
void		ft_print_matrix(int **map, int width);
void		ft_print_arr(int *lems_in_rooms, int n);
void		ft_print_lems(int *lems_in_rooms,
				t_paths paths, t_lem_in lem_in, int max_path);

void		ft_move_leams_in_path(t_matrix *condition_of_ants,
				t_matrix paths_table, int k);
void		ft_crt_len_table(t_paths paths, int **len_table,
				t_matrix aj, t_lem_in lem_in);
int			ft_calc_lems(t_paths paths, t_matrix aj,
				int **lems_in_rooms, t_lem_in lem_in);

void		ft_q_push(t_queue **q, int node);
int			ft_q_empty(t_queue *q);
int			ft_q_front(t_queue *q);
void		ft_q_pop(t_queue **q);

void		assert(int expr, const char *msg);
void		error_exit(const char *msg);
int			bf_shortest_path(t_matrix *aj,
				t_matrix *paths_map, int stat, int end);
int			ft_srch_max(int *len_table, int len);
int			ft_srch_max1(int *len_table, int len);
int			ft_srch_min(int *len_table);
t_paths		lem_in_solve(t_matrix *aj, t_lem_in lem_in);
void		lem_in_output1(int **paths, t_matrix aj, t_lem_in lem_in);
int			ft_calc_lems1(t_paths paths, t_matrix aj,
				int **lems_in_rooms, t_lem_in lem_in);

#endif
