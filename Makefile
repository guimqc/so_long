SRCS = src/main.c

NAME = so_long

CC = gcc -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

RM = rm -f

all:
	$(CC) $(SRCS)