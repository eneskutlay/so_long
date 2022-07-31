/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:17:26 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/31 04:02:18 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit (0);
}

void	catch_moves(t_data *mlx)
{
	int			prev_x;
	int			prev_y;
	static int	moves;

	prev_x = mlx->p_row;
	prev_y = mlx->p_col;
	fill_p_act(mlx);
	if (prev_x != mlx->p_row || prev_y != mlx->p_col)
		printf("moves = %d \n", ++moves);
}

int	key_hook(int key, t_data *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		free_map(&mlx);
		exit (0);
	}
	else if (key == 1)
		mlx->key = 'S';
	else if (key == 13)
		mlx->key = 'W';
	else if (key == 0)
		mlx->key = 'A';
	else if (key == 2)
		mlx->key = 'D';
	else
		mlx->key = 'Z';
	if (mlx->key == 'A' || mlx->key == 'S'
		|| mlx->key == 'W' || mlx->key == 'D')
		catch_moves(mlx);
	return (0);
}

int	catch_hook(t_data *mlx)
{
	mlx_hook(mlx->mlx_win, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, (1L << 8), close_window, mlx);
	return (0);
}
