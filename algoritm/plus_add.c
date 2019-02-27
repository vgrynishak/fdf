/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 13:54:11 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/25 13:54:12 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	plus_line(int *i, int *x2, int *y2, int x)
{
	*i = 0;
	*x2 = x;
	(*y2)++;
}

void	plus_dot(char **piece, int *x2, int *i)
{
	(*i)++;
	(*x2)++;
	(*piece)++;
}

int		plus_star(t_filler filler, int *only_one, int y, int x)
{
	if (filler.map[y][x] == filler.my_char)
	{
		if (*only_one == 0)
			return (0);
		(*only_one)--;
	}
	return (1);
}

void	plus_best_position(t_filler *filler, int len, int x, int y)
{
	filler->best_len = len;
	filler->best_x = x;
	filler->best_y = y;
}
