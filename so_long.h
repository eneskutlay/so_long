/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:43:11 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/31 00:55:00 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

void	check_ber(char *argv);

char	*ft_fit_buff(int fd, char *left_str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_catch_new_line(char *left_str);
char	*ft_new_next_str(char *left_str);

void	set_if_no(t_data *mlx);
void	check_if_c(t_data *mlx, int row, int col);
void	move_player(t_data *mlx, int row, int col);
void	free_map(t_data **mlx);

void	check_perimeter(t_data *m);
void	check_values3(t_data *m, int row);
void	check_values2(t_data *m, int row);
void	check_values1(t_data *m, int row);
void	check_errors(t_data *mlx);

void	fill_p(t_data *m, int x, int y);
void	fill_c_e(t_data *m);
void	fill_1_0(t_data *m);
void	fill_map(t_data *mlx);

void	set_key(t_data *mlx);
void	fill_p_act(t_data *mlx);
#endif
