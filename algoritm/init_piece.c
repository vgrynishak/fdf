/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:40:45 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/22 15:40:46 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	push_piece(char *line, t_filler *filler, int *len_piece)
{
	int i;

	i = 0;
	if (*len_piece <= filler->piece_y)
	{
		if (*len_piece == filler->piece_y)
			filler->piece = (char **)malloc(sizeof(char *) * filler->piece_y);
		filler->piece[filler->piece_y - *len_piece] = (char *)
		malloc(sizeof(char) * filler->piece_x + 1);
		while (i < filler->piece_x)
		{
			filler->piece[filler->piece_y - *len_piece][i] = line[i];
			i++;
		}
		filler->piece[filler->piece_y - *len_piece][i] = '\0';
	}
	*len_piece -= 1;
}

static void	take_size_piece(char *line, t_filler *filler, int *len)
{
	while (!(*line >= '1' && *line <= '9'))
		line++;
	filler->piece_y = ft_atoi(line);
	while (*line != ' ')
		line++;
	filler->piece_x = ft_atoi(line);
	*len = filler->piece_y;
}

int			init_piece(t_filler *filler)
{
	char	*line;
	int		len_piece;

	len_piece = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Piece"))
			take_size_piece(line, filler, &len_piece);
		else if (len_piece)
		{
			push_piece(line, filler, &len_piece);
			if (len_piece == 0)
			{
				free(line);
				return (1);
			}
		}
		free(line);
	}
	return (0);
}
