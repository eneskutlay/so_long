/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:07:53 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/30 05:29:31 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_if_no(t_data *mlx)
{
	if (mlx->key == 'S')
		mlx->p_row -= 1;
	if (mlx->key == 'W')
		mlx->p_row += 1;
	if (mlx->key == 'A')
		mlx->p_col += 1;
	if (mlx->key == 'D')
		mlx->p_col -= 1;
}

void	check_if_c(t_data *mlx, int row, int col)
{
	if (mlx->map[mlx->p_row][mlx->p_col] == 'C')
	{
		mlx->map[mlx->p_row][mlx->p_col] = 0;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0, col * 64,
			row * 64);
		mlx->c--;
	}
	if (mlx->c == 0 && mlx->exit == 0)
	{
		mlx->exit = 1;
		mlx->e_row = get_p_row(mlx, 'E');
		mlx->e_col = get_p_col(mlx, 'E');
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
			mlx->e_col * 64, mlx->e_row * 64);
		mlx->img_y = mlx_xpm_file_to_image(mlx->mlx, "xpm/open.xpm",
				&mlx->width, &mlx->height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_y,
			mlx->e_col * 64, mlx->e_row * 64);
	}
}

void	move_player(t_data *mlx, int row, int col)
{
	check_if_c(mlx, row, col);
	if (mlx->map[mlx->p_row][mlx->p_col] == 'E' && mlx->exit == 0)
		set_if_no(mlx);
	else if (mlx->map[mlx->p_row][mlx->p_col] == 'E' && mlx->exit == 1)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit (0);
	}
	else if (mlx->map[mlx->p_row][mlx->p_col] != '1')
	{
		check_key_s_d(mlx, row, col);
		check_key_a_w(mlx, row, col);
	}
	else
		set_if_no(mlx);
}
