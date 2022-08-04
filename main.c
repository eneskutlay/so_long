/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:52:35 by ekutlay           #+#    #+#             */
/*   Updated: 2022/08/05 00:25:01 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *m, char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	m->col_len = ft_strlen_lib((line = get_next_line(fd)));
	free(line);
	close(fd);
	fd = open(str, O_RDONLY);
	m->row_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		m->row_len++;
	}
	free(line);
	m->c = 0;
	m->key = 'Z';
	m->moves = 0;
	m->exit = 0;
}

int	create_map(t_data *m, char *str)
{
	int		fd;
	int		col;
	int		row;
	char	*line;

	m->map = (char **)malloc(sizeof(char *) * (m->row_len + 1));
	if (!m->map)
		return (0);
	row = 0;
	fd = open(str, O_RDONLY);
	while (row < m->row_len)
	{
		line = get_next_line(fd);
		col = 0;
		m->map[row] = malloc(sizeof(char) * (m->col_len + 1));
		while (col < m->col_len)
		{
			m->map[row][col] = line[col];
			col++;
		}
		free(line);
		m->map[row][col] = '\0';
		row++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	m;
	char	*str;

	if (argc != 2)
	{
		write(1, "ARGV Error\n", 12);
		exit (0);
	}
	str = argv[1];
	check_ber(str);
	initialize(&m, str);
	create_map(&m, str);
	m.col_len -= 1;
	check_errors(&m);
	fill_map(&m);
	return (0);
}
