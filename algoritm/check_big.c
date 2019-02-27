/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:04:21 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/26 19:04:22 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		find_left(t_filler filler, int *y_max, int *x_max, char c)
{
	int y;
	int x;

	y = 0;
	*y_max = 100;
	*x_max = 100;
	while (y < filler.map_y)
	{
		x = 0;
		while (x < filler.map_x)
		{
			if (filler.map[y][x] == c)
			{
				if (x <= *x_max)
				{
					*y_max = y;
					*x_max = x;
				}
			}
			x++;
		}
		y++;
	}
}

void		find_max_down(t_filler filler, int *y_max, int *x_max)
{
	int y;
	int x;

	y = 0;
	*y_max = 0;
	*x_max = 0;
	while (y < filler.map_y)
	{
		x = 0;
		while (x < filler.map_x)
		{
			if (filler.map[y][x] == filler.enemy)
			{
				if (y > *y_max)
				{
					*y_max = y;
					*x_max = x;
				}
			}
			x++;
		}
		y++;
	}
}

int			best_y(t_filler filler, char c)
{
	int y;
	int x;

	y = 0;
	while (y < filler.map_y)
	{
		x = 0;
		while (x < filler.map_x)
		{
			if (filler.map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int			check_big(t_filler filler, int y, int x)
{
	int y_my_l;
	int x_my_l;
	int y_max;
	int x_max;

	if (filler.map_y >= 16 && best_y(filler, filler.enemy) <
		best_y(filler, filler.my_char))
	{
		find_max_down(filler, &y_max, &x_max);
		find_left(filler, &y_my_l, &x_my_l, filler.my_char);
		if (x_my_l != 0 && x_my_l >= x_max - 5)
			return (ft_abs(y_max - y) + ft_abs(0 - x));
		else if (filler.map_y > 90 && x_my_l != 0)
		{
			find_left(filler, &y_max, &x_max, filler.enemy);
			if (x_my_l >= x_max - 2)
				return (ft_abs(x_max + 2 - x) + ft_abs(0 - y));
		}
	}
	return (0);
}
