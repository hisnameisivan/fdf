# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 23:48:43 by waddam            #+#    #+#              #
#    Updated: 2020/09/02 16:50:41 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/main.c\
	  src/additions.c\
	  src/parsing.c\
	  src/point.c\
	  src/read_map.c\
# SRCDIR = src/
# SRCPTH = $(addprefix $(SRCDIR), $(SRC))
# OBJ = $(SRCPTH:%.c=%.o)
# DEP = $(SRCPTH:%.c=%.d)
OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

all: $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -I includes/ -I libft/ -I minilibx/ -I /usr/include/X11 -I /usr/include/X11/extensions -MD -c $< -o $@

include $(wildcard *.d)

libft/libft.a:
	make -C libft/

$(NAME): $(OBJ) libft/libft.a minilibx/libmlx_Linux.a
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) libft/libft.a minilibx/libmlx_Linux.a -lX11 -lXext
	# rm -f $(OBJ)  # del
	# rm -f $(DEP)  # del

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#gcc -Wall -Wextra -Werror src/main.c src/parsing.c src/read_map.c libft/libft.a gnl/get_next_line.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
