NAME = lem-in
LIBFT = $(addprefix libft/, libft.a)

OPTIONS = -I. -Ilibft/includes

SRC = \
		src/main.c \
		src/debug.c \
		src/error_handling.c \
        src/matrix.c \
		src/matrix_init.c \
        src/array.c \
		src/find_paths.c \
        src/lem_in_read.c \
		src/lem_in_output.c \
		src/arr_functions.c \
		src/crt_len_table.c \
		src/stack_functions.c \
		src/suurballe.c \
		src/remove_inverse_pahts.c \
		src/path.c \
		src/solve.c \
		src/node_collapse.c \
		src/bellman_ford.c \
		src/ft_print_functions.c \
		src/free.c \

FLS = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o:%.c
		gcc $(OPTIONS) $(FLS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	gcc $(FLS) $(OBJ) -o $(NAME) $(OPTIONS) -L libft -lft

run : $(NAME)
	@./$(NAME) -d maps/qqq_ordered

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
