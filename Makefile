NAME = lem-in
LIBFT = $(addprefix libft/, libft.a)

SRC = ft_lem_in.c \
	ft_read_map.c \
	ft_crt_map.c \

FLS = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o:%.c
		gcc $(FLS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	gcc $(FLS) $(OBJ) -o $(NAME) -L libft -lft

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
