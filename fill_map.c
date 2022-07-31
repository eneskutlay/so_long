/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:17:45 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/31 00:42:36 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_p(t_data *m, int x, int y)
{
	int	row;
	int	col;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (row == m->p_row && col == m->p_col && m->key == 'Z')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_p, x, y);
			else if (row == m->p_row && col == m->p_col && m->key != 'Z')
			{
				set_key(m);
				move_player(m, row, col);
			}
			x = x + 64;
			col++;
		}
		y = y + 64;
		row++;
	}
}

void	fill_c_e(t_data *m)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == 'C')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_c, x, y);
			if (m->map[row][col] == 'E')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_e, x, y);
			x = x + 64;
			col++;
		}
		y = y + 64;
		row++;
	}
}

void	fill_1_0(t_data *m)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == '1')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_1, x, y);
			else if (m->map[row][col] == '0')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_0, x, y);
			x = x + 64;
			col++;
		}
		y = y + 64;
		row++;
	}
}

void	fill_map(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 64 * mlx->col_len,
			64 * mlx->row_len, "Spiderman!");
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx, "xpm/wall.xpm",
			&mlx->width, &mlx->height);
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx, "xpm/square.xpm",
			&mlx->width, &mlx->height);
	mlx->img_c = mlx_xpm_file_to_image (mlx->mlx, "xpm/gold.xpm",
			&mlx->width, &mlx->height);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx, "xpm/spider.xpm",
			&mlx->width, &mlx->height);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx, "xpm/close.xpm",
			&mlx->width, &mlx->height);
	mlx->p_row = get_p_row(mlx, 'P');
	mlx->p_col = get_p_col(mlx, 'P');
	fill_p(mlx, 0, 0);
	fill_1_0(mlx);
	fill_c_e(mlx);
	catch_hook(mlx);
	mlx_loop(mlx);
}
