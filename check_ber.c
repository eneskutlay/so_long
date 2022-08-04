/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:22:55 by ekutlay           #+#    #+#             */
/*   Updated: 2022/08/05 00:27:22 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *argv)
{
	int	i;
	int	e;
	int	l;

	i = 0;
	e = 0;
	l = ft_strlen_lib(argv);
	while (argv[i] != '.')
		i++;
	i++;
	if (argv[i] != 'b')
		e++;
	i++;
	if (argv[i] != 'e')
		e++;
	i++;
	if (argv[i] != 'r')
		e++;
	if (argv[i] != l)
		e++;
	if (e != 0)
	{
		write (1, "Map Error\n", 10);
		exit (0);
	}
}
