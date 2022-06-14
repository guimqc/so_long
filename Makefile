SRCS = main.c src/map.c src/hook.c src/display.c src/error.c src/print_asset.c \

OBJ = $(SRCS:%c=%o)

NAME = so_long

CC = gcc

CFLAGS =  -Wall -Werror -Wextra -c

RM = rm -f

MAKELIB = cd lib/libft && make -s

LIB = lib/libft/libft.a

MAKELIBX = cd lib/mlx && make -s

LIBX = lib/mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKELIB)
	$(MAKELIBX)
	$(CC) $(OBJ) $(LIB) $(LIBX) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	cd lib/libft && make clean -s
	$(RM) $(OBJ)

fclean: clean
	cd lib/libft && make fclean -s
	cd lib/mlx/ && make clean
	$(RM) $(NAME) -s

re: fclean all
