NAME = lem-in
LIBFT = $(addprefix libft/, libft.a)

OPTIONS = -I. -Ilibft/includes

SRC = \
		src/main.c \
        src/matrix.c \
        src/array.c \
		src/find_paths.c \
        src/lem_in_read.c \
		src/lem_in_output.c \
		src/ft_trnsfr_paths.c \
		src/suurballe.c \
		src/bellman_ford.c \

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
	./$(NAME)

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
