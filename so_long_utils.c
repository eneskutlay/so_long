/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:30:18 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/31 02:52:13 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	transformaitor(t_data *mlx, int row, int col)
{
	int	x;

	x = 0;
	if (mlx->key == 'S')
		x = row - 1;
	else if (mlx->key == 'W')
		x = row + 1;
	else if (mlx->key == 'A')
		x = col + 1;
	else if (mlx->key == 'D')
		x = col - 1;
	return (x);
}

void	check_key_s_d(t_data *mlx, int row, int col)
{
	int	x;

	x = transformaitor(mlx, row, col);
	if (mlx->key == 'S')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 64, row * 64);
		if (mlx->map[x][col] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				col * 64, x * 64);
	}
	else if (mlx->key == 'D')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 64, row * 64);
		if (mlx->map[row][x] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				x * 64, row * 64);
	}
}

void	check_key_a_w(t_data *mlx, int row, int col)
{
	int	x;

	x = transformaitor(mlx, row, col);
	if (mlx->key == 'A')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 64, row * 64);
		if (mlx->map[row][x] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				x * 64, row * 64);
	}
	else if (mlx->key == 'W')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 64, row * 64);
		if (mlx->map[x][col] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				col * 64, x * 64);
	}
}

int	get_p_row(t_data *mlx, char c)
{
	int	row;
	int	col;
	int	row_p;

	row = 0;
	while (row < mlx->row_len)
	{
		col = 0;
		while (col < mlx->col_len)
		{
			if (mlx->map[row][col] == c)
			{
				row_p = row;
				return (row_p);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	get_p_col(t_data *mlx, char c)
{
	int	row;
	int	col;
	int	col_p;

	row = 0;
	while (row < mlx->row_len)
	{
		col = 0;
		while (col < mlx->col_len)
		{
			if (mlx->map[row][col] == c)
			{
				col_p = col;
				return (col_p);
			}
			col++;
		}
		row++;
	}
	return (0);
}
