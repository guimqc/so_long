SRCS = src/main.c src/map.c

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
	cd mlx && $(RM) *.o

fclean: clean
	cd libft && make fclean -s
	cd mlx && make clean -s
	$(RM) $(NAME) -s

re: fclean all