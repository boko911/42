# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 10:14:55 by nbuhler           #+#    #+#              #
#    Updated: 2018/02/08 10:14:58 by nbuhler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../interface_RT
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

GCC_FLGS = -Werror -Wextra -Wall -g
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC_NAME = btn.c btn2.c btn3.c btn4.c \
		check_cam.c check_cam2.c check_cam3.c \
		check_light.c \
		check_mat.c check_mat2.c \
		check_shape.c \
		check_input_image.c \
		check_input_texture.c \
		connect_w.c \
		connect_w2.c \
		connect_w3.c \
		connect_w4.c \
		get_color_mat.c \
		get_shape_mat.c get_shape_mat2.c \
		light.c \
		main.c \
		reinitialize.c \
		text_cam.c \
		text_mat.c text_mat2.c \
		text_shape.c \
		text_shape2.c \
		text_image.c \
		text_texture.c \
		tool.c \
		tool2.c \
		tool3.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

#@echo "$(GREEN)$(NAME)$(DEFAULT) created."

$(NAME): $(OBJ)
	@$(CC) $(GCC_FLGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@if ! [ -d "$(OBJ_PATH)" ]; then mkdir $(OBJ_PATH); fi
	@$(CC) -c $(GCC_FLGS) $(INC) -o $@ $(CFLAGS) $<
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."
re: fclean all
