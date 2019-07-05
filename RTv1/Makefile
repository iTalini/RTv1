# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurilen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 12:19:02 by akurilen          #+#    #+#              #
#    Updated: 2018/09/10 15:21:22 by akurilen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC =	src/area.c \
		src/start.c \
		src/shadows.c \
		src/key_mouse.c \
		src/line.c \
		src/color.c \
		src/calc_v3.c \
		src/line_2.c \
		src/check.c \
		src/next.c \
		src/ray_trace.c \
		src/obj_cord.c \
		src/draw.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create RTv1"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

run:
	./RTv1 Test 3>pt1 4>pt2 5>pt3 6>pt4 7>pt5 8>pt6 9>pt7 10>pt8

all: $(NAME)
.PHONY: clean fclean re all test
