SRCS = src/main.c

NAME = so_long

CC = gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit -o $(NAME)

RM = rm -f

MAKELIB = cd libft && make -s

LIB = libft/libft.a

MAKELIBX = cd mlx && make -s

LIBX = mlx/libmlx.a

all: $(NAME)

$(NAME):
	$(MAKELIB)
	$(MAKELIBX)
	$(CC) $(SRCS) $(LIB) $(LIBX)

clean:
	cd libft && make clean -s

fclean: clean
	cd libft && make fclean -s
	$(RM) $(NAME) -s

re: fclean all