# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 03:21:27 by ekutlay           #+#    #+#              #
#    Updated: 2022/07/31 03:56:06 by ekutlay          ###   ########.fr        #
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
	$(CC) $(FLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@ echo "so_long compiled 🐒"

clean:
	@ rm -rf so_long

fclean: clean
	@rm -rf so_long
	@rm -rf so_long.dSYM
	@ echo "so_long cleaned 🧤"

re: fclean all

.PHONY : all clean fclean re
