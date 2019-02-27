/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_viso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:18 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/25 15:09:21 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	push_map(char *line, t_key *fdf, int *len_map)
{
	int i;

	if (*len_map <= fdf->map_y)
	{
		line += 4;
		(fdf->map)[fdf->map_y - *len_map] = (char *)
		malloc(sizeof(char) * (fdf->map_x + 1));
		i = 0;
		while (i < fdf->map_x)
		{
			if (line[i] == 'x' || line[i] == 'o')
				line[i] -= 32;
			(fdf->map)[fdf->map_y - *len_map][i] = line[i];
			i++;
		}
		fdf->map[fdf->map_y - *len_map][i] = '\0';
	}
	else
		fdf->map = (char **)malloc(sizeof(char *) * fdf->map_y);
	*len_map -= 1;
}

static void	take_score(char *line, t_key *fdf)
{
	line += 3;
	if (*line == fdf->my_char)
	{
		line += 6;
		fdf->my_score = (ft_atoi(line));
	}
	else if (*line == fdf->enemy)
	{
		line += 6;
		fdf->enemy_score = (ft_atoi(line));
	}
}

static void	take_size_map(char *line, t_key *fdf, int *len)
{
	while (!(*line >= '1' && *line <= '9'))
		line++;
	fdf->map_y = ft_atoi(line);
	while (*line != ' ')
		line++;
	fdf->map_x = ft_atoi(line);
	*len = fdf->map_y + 1;
}

int			init_map_viso(t_key *fdf)
{
	char	*line;
	int		len_map;

	len_map = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
			take_size_map(line, fdf, &len_map);
		else if (len_map)
		{
			push_map(line, fdf, &len_map);
			if (len_map == 0)
			{
				free(line);
				return (1);
			}
		}
		else if (ft_strstr(line, "=="))
			take_score(line, fdf);
		free(line);
	}
	return (0);
}
