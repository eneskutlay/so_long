# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 03:21:27 by ekutlay           #+#    #+#              #
#    Updated: 2022/08/02 00:37:07 by ekutlay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
SRC  = catch_hook.c \
		check_ber.c \
		check_errors.c \
		fill_map.c \
		fill_p_act.c \
		free_map.c \
		ft_strlen.c \
		get_next_line.c \
		get_next_line_utils.c \
		main.c \
		move_player.c \
		so_long_utils.c \

all : $(NAME)

$(NAME) : $(SRC)
	make -C ./mlx
	$(CC) $(FLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C ./mlx clean
	@ rm -rf so_long

fclean: clean
	@rm -rf so_long
	@rm -rf so_long.dSYM

re: fclean all

.PHONY : all clean fclean re
