/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:50:33 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/25 12:11:19 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*change_piece(t_filler filler)
{
	const int	len = filler.piece_x * filler.piece_y;
	char		*piece;
	int			i;
	int			y;
	int			x;

	y = 0;
	i = 0;
	piece = (char *)malloc(sizeof(char) * (len + 1));
	while (y < filler.piece_y)
	{
		x = 0;
		while (x < filler.piece_x)
		{
			piece[i] = filler.piece[y][x];
			x++;
			i++;
		}
		y++;
	}
	piece[i] = '\0';
	return (piece);
}

int			can_put(int y, int x, t_filler filler, char *piece)
{
	int only_one;
	int i;
	int x2;

	only_one = 1;
	i = 0;
	x2 = x;
	while (*piece)
	{
		if (i >= filler.piece_x)
			plus_line(&i, &x2, &y, x);
		else if (*piece == '.')
			plus_dot(&piece, &x2, &i);
		else if (*piece == '*' && y < filler.map_y && y >= 0 && x2 >= 0 &&
				x2 < filler.map_x && filler.map[y][x2] != filler.enemy)
		{
			if (!(plus_star(filler, &only_one, y, x2)))
				return (0);
			plus_dot(&piece, &x2, &i);
		}
		else
			return (0);
	}
	return ((only_one == 1) ? 0 : 1);
}

int			find_len(t_filler filler, int y, int x)
{
	int		y_l;
	int		x_l;
	int		len;
	int		tmp;

	len = 2000;
	if (check_big(filler, y, x))
		return (check_big(filler, y, x));
	y_l = 0;
	while (y_l < filler.map_y)
	{
		x_l = 0;
		while (x_l < filler.map_x)
		{
			if (filler.map[y_l][x_l] == filler.enemy)
			{
				tmp = ft_abs(y_l - y) + ft_abs(x_l - x);
				if (tmp <= len)
					len = tmp;
			}
			x_l++;
		}
		y_l++;
	}
	return (len);
}

void		find_best_position(t_filler filler)
{
	char	*piece;
	int		len;
	int		x;
	int		y;

	y = 1 - filler.piece_y;
	piece = change_piece(filler);
	while (y < filler.map_y)
	{
		x = 1 - filler.piece_x;
		while (x < filler.map_x)
		{
			if (can_put(y, x, filler, piece) == 1)
			{
				len = find_len(filler, y, x);
				if (len < filler.best_len)
					plus_best_position(&filler, len, x, y);
			}
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", filler.best_y, filler.best_x);
	free(piece);
}
