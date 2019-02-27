/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_viso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:13:41 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/25 15:13:42 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		options(t_key fdf)
{
	mlx_string_put(fdf.mlx_ptr, fdf.new_window, 430, 10, 0x00ff00,
				"my_players : GREEN");
	mlx_string_put(fdf.mlx_ptr, fdf.new_window, 830, 10, 0xff0000,
				"enemy : RED");
	if (fdf.my_score || fdf.enemy_score)
	{
		mlx_string_put(fdf.mlx_ptr, fdf.new_window, 430, 27, 0x00ff00,
					ft_itoa(fdf.my_score));
		mlx_string_put(fdf.mlx_ptr, fdf.new_window, 830, 27, 0xff0000,
					ft_itoa(fdf.enemy_score));
	}
}

void		ft_clear_fdf(t_key *fdf)
{
	int i;

	i = 0;
	while (i < fdf->map_y)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
}

void		ft_define_viso(t_key *fdf)
{
	if (fdf->map_y == 100)
		fdf->zoom = 10;
	else if (fdf->map_y == 15)
		fdf->zoom = 50;
	else
		fdf->zoom = 30;
	fdf->color = 0xffffff;
	fdf->position = 0;
	fdf->score = 1;
	fdf->my_score = 0;
	fdf->enemy_score = 0;
}
