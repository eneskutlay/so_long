/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:22:55 by ekutlay           #+#    #+#             */
/*   Updated: 2022/07/30 02:26:06 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *argv)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
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
	if (e != 0)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
}
