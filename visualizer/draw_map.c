/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:18:46 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/20 12:18:46 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_coordinat	proection_xy(t_key fdf, int x, int y)
{
	t_coordinat	a;

	a.x = x * fdf.zoom;
	a.y = y * fdf.zoom;
	a.color = fdf.color;
	return (a);
}

static void			draw_square(int x, int y, t_key *fdf, int color)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->zoom)
	{
		j = 0;
		while (j < fdf->zoom)
		{
			*((unsigned int *)(fdf->image.put_image + (y + i) *
						fdf->image.size_line + 4 * (x + j))) = color;
			j++;
		}
		i++;
	}
}

static void			main_robota(t_key *fdf, t_coordinat *tmp, int i, int j)
{
	t_coordinat			start;

	start = proection_xy(*fdf, j, i);
	if (i != fdf->map_y && j != fdf->map_x && fdf->map[i][j] == fdf->my_char)
		draw_square(j * fdf->zoom, i * fdf->zoom, fdf, 0x00ff00);
	else if (i != fdf->map_y && j != fdf->map_x && fdf->map[i][j] == fdf->enemy)
		draw_square(j * fdf->zoom, i * fdf->zoom, fdf, 0xff0000);
	if (j)
		draw_line(start, tmp[j - 1], *fdf);
	if (i)
		draw_line(start, tmp[j], *fdf);
	tmp[j] = start;
}

void				draw_map(t_key *fdf)
{
	int					i;
	int					j;
	t_coordinat			*tmp;

	tmp = (t_coordinat *)malloc(sizeof(t_coordinat) * (fdf->map_x + 1));
	i = 0;
	while (i <= fdf->map_y)
	{
		j = 0;
		while (j <= fdf->map_x)
		{
			main_robota(fdf, tmp, i, j);
			j++;
		}
		i++;
	}
	free(tmp);
}
