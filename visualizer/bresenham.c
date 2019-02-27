/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:54:24 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/09 15:54:25 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	your_way(int i)
{
	if (i == 0)
		return (0);
	return ((i < 0) ? -1 : 1);
}

static void	line_cloze_x(t_coordinat start, t_coordinat end, t_key *fdf,
					int error)
{
	const int	inc_x = your_way(end.x - start.x);
	const int	inc_y = your_way(end.y - start.y);
	int			dx;
	int			dy;
	int			i;

	dx = ((end.x - start.x) < 0) ? (start.x - end.x) : (end.x - start.x);
	dy = ((end.y - start.y) < 0) ? (start.y - end.y) : (end.y - start.y);
	i = 0;
	while (i < dx)
	{
		error -= dy;
		if (error < 0)
		{
			error += dx;
			start.x += inc_x;
			start.y += inc_y;
		}
		else
			start.x += inc_x;
		if (start.y < 2000 && start.x < 2000 && start.y >= 0 && start.x >= 0)
			*((unsigned int *)((fdf->image).put_image + (start.y *
				((fdf->image).size_line) + 4 * start.x))) = start.color;
		i++;
	}
}

static void	line_cloze_y(t_coordinat start, t_coordinat end, t_key *fdf,
						int error)
{
	const int	inc_x = your_way(end.x - start.x);
	const int	inc_y = your_way(end.y - start.y);
	int			dx;
	int			dy;
	int			i;

	dx = ((end.x - start.x) < 0) ? (start.x - end.x) : (end.x - start.x);
	dy = ((end.y - start.y) < 0) ? (start.y - end.y) : (end.y - start.y);
	i = 0;
	while (i < dy)
	{
		error -= dx;
		if (error < 0)
		{
			error += dy;
			start.x += inc_x;
			start.y += inc_y;
		}
		else
			start.y += inc_y;
		if (start.y < 2000 && start.x < 2000 && start.y >= 0 && start.x >= 0)
			*((unsigned int *)((fdf->image).put_image + (start.y *
				((fdf->image).size_line) + 4 * start.x))) = start.color;
		i++;
	}
}

void		draw_line(t_coordinat start, t_coordinat end, t_key fdf)
{
	int		dx;
	int		dy;
	int		error;

	dx = end.x - start.x;
	dy = end.y - start.y;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;
	if (dx > dy)
	{
		error = dx / 2;
		line_cloze_x(start, end, &fdf, error);
	}
	else
	{
		error = dy / 2;
		line_cloze_y(start, end, &fdf, error);
	}
}
