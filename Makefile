SRCS = main.c src/*.c \

NAME = so_long

CC = gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit -o $(NAME)

RM = rm -f

MAKELIB = cd lib/libft && make -s

LIB = lib/libft/libft.a

MAKELIBX = cd lib/mlx && make -s

LIBX = lib/mlx/libmlx.a

all: $(NAME)

$(NAME):
	$(MAKELIB)
	$(MAKELIBX)
	$(CC) $(SRCS) $(LIB) $(LIBX)

clean:
	cd lib/libft && make clean -s

fclean: clean
	cd lib/libft && make fclean -s
	$(RM) $(NAME) -s

re: fclean all

norm:
	norminette $(SRCS) so_long.h