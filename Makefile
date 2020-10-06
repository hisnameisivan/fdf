# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 23:48:43 by waddam            #+#    #+#              #
#    Updated: 2020/10/04 21:09:52 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/main.c\
	  src/additions.c\
	  src/parsing.c\
	  src/point.c\
	  src/point_methods.c\
	  src/read_map.c\
	  src/graphics.c\
	  src/positioning.c\
	  src/events.c
OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

all: $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -I includes/ -I libft/ -I minilibx/ -I /usr/include/X11 -I /usr/include/X11/extensions -MD -c $< -o $@

include $(wildcard $(DEP))

minilibx/libmlx_Linux.a:
	make -C minilibx/

libft/libft.a:
	make -C libft/

$(NAME): $(OBJ) libft/libft.a minilibx/libmlx_Linux.a
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) libft/libft.a minilibx/libmlx_Linux.a -lX11 -lXext -lm

clean:
	rm -f $(OBJ) $(DEP)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f minilibx/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re
