# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waddam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 23:48:43 by waddam            #+#    #+#              #
#    Updated: 2020/02/29 01:24:27 by waddam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/main.c src/read_map.c gnl/get_next_line.c
# SRCDIR = src/
# SRCPTH = $(addprefix $(SRCDIR), $(SRC))
# OBJ = $(SRCPTH:%.c=%.o)
# DEP = $(SRCPTH:%.c=%.d)
OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

all: $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -O2 -MD -c $< -o $@

include $(wildcard *.d)

$(NAME): $(OBJ) libft/libft.a minilibx_macos/libmlx.a
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	# rm -f $(OBJ)  # del
	# rm -f $(DEP)  # del

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#gcc -Wall -Wextra -Werror src/main.c src/read_map.c libft/libft.a gnl/get_next_line.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit