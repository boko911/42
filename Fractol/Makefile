# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 13:06:16 by nbuhler           #+#    #+#              #
#    Updated: 2017/04/28 13:06:27 by nbuhler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fractol.h

SRC =	mandelbrot.c \
		mouse_click_hook.c \
		mouse_move_hook.c \
		error.c \
		menu.c \
		calcul.c \
		julia.c \
		window.c \
		keyboard_hook.c \
		keyboard_hook_2.c \
		main.c 

		
OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

