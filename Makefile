SRCS = main.c

OBJ = $(SRCS:%c=%o)

NAME = so_long

CC = gcc -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

RM = rm -f

all: