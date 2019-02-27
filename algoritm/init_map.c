/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:34:53 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/22 15:34:53 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	push_map(char *line, t_filler *filler, int *len_map)
{
	int i;

	if (*len_map <= filler->map_y)
	{
		line += 4;
		(filler->map)[filler->map_y - *len_map] = (char *)
		malloc(sizeof(char) * (filler->map_x + 1));
		i = 0;
		while (i < filler->map_x)
		{
			if (line[i] == 'x' || line[i] == 'o')
				line[i] -= 32;
			(filler->map)[filler->map_y - *len_map][i] = line[i];
			i++;
		}
		filler->map[filler->map_y - *len_map][i] = '\0';
	}
	else
		filler->map = (char **)malloc(sizeof(char *) * filler->map_y);
	*len_map -= 1;
}

static void	take_size_map(char *line, t_filler *filler, int *len)
{
	while (!(*line >= '1' && *line <= '9'))
		line++;
	filler->map_y = ft_atoi(line);
	while (*line != ' ')
		line++;
	filler->map_x = ft_atoi(line);
	*len = filler->map_y + 1;
}

int			init_map(t_filler *filler)
{
	char	*line;
	int		len_map;

	len_map = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
			take_size_map(line, filler, &len_map);
		else if (len_map)
		{
			push_map(line, filler, &len_map);
			if (len_map == 0)
			{
				free(line);
				return (1);
			}
		}
		free(line);
	}
	return (0);
}
