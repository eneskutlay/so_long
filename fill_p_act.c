/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_p_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:47:04 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/31 00:52:46 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_key(t_data *mlx)
{
	if (mlx->key == 'S')
		mlx->p_row += 1;
	if (mlx->key == 'W')
		mlx->p_row -= 1;
	if (mlx->key == 'A')
		mlx->p_col -= 1;
	if (mlx->key == 'D')
		mlx->p_col += 1;
}

void	fill_p_act(t_data *mlx)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	set_key(mlx);
	while (row < mlx->row_len)
	{
		col = 0;
		x = 0;
		while (col < mlx->col_len)
		{
			if (row == mlx->p_row && col == mlx->p_col)
				move_player(mlx, row, col);
			x = x + 64;
			col++;
		}
		y = y + 64;
		row++;
	}
}
