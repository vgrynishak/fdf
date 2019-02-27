/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:59:03 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/17 16:59:03 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_clear(t_filler *f)
{
	int i;

	i = 0;
	while (i < f->map_y)
	{
		free(f->map[i]);
		i++;
	}
	free(f->map);
	i = 0;
	while (i < f->piece_y)
	{
		free(f->piece[i]);
		i++;
	}
	free(f->piece);
}

static int	init_players(t_filler *filler)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (!(ft_strcmp(line, "$$$ exec p1 : [./vgrynish.filler]")))
		{
			filler->position = 1;
			filler->enemy = 'X';
			filler->my_char = 'O';
			free(line);
			return (1);
		}
		if (!(ft_strcmp(line, "$$$ exec p2 : [./vgrynish.filler]")))
		{
			filler->position = -1;
			filler->enemy = 'O';
			filler->my_char = 'X';
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

int			main(void)
{
	t_filler	filler;

	filler.position = 0;
	while (1)
	{
		if (!filler.position && !(init_players(&filler)))
			break ;
		if (!(init_map(&filler)))
			break ;
		if (!(init_piece(&filler)))
			break ;
		filler.best_x = 0;
		filler.best_y = 0;
		filler.best_len = 1000;
		find_best_position(filler);
		ft_clear(&filler);
	}
	return (0);
}
