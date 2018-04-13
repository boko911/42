# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/24 13:02:11 by agrosset          #+#    #+#              #
#    Updated: 2016/06/13 14:33:26 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmtx.a
INPUT=	mtx_init.c \
		mtx_init_mtx.c \
		mtx_trans.c \
		mtx_dotproduct.c \
		mtx_dot.c \
		mtx_add.c \
		mtx_sub.c \
		mtx_negate.c \
		mtx_mult.c \
		mtx_product.c \
		mtx_invert.c

OBJ=$(subst .c,.o,$(INPUT))
FLAGS=-Wall -Werror -Wextra -Iinclude -g

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -f $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all
