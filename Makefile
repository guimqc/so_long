SRCS = src/main.c src/valid_map.c

OBJ = $(SRCS:%c=%o)

NAME = so_long

CC = gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit -o $(NAME)

RM = rm -f

MAKELIB = cd libft && make -s

LIB = libft/libft.a

all:
	$(MAKELIB)
	$(CC) $(SRCS) $(LIB)

clean:
	cd libft && make clean

fclean: clean
	cd libft && make fclean
	$(RM) $(NAME)
