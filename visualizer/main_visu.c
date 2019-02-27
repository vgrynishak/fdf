/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:11:39 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/23 15:11:39 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	init_players_viso(t_key *fdf)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (!(ft_strcmp(line, "$$$ exec p1 : [./vgrynish.filler]")))
		{
			fdf->position = 1;
			fdf->enemy = 'X';
			fdf->my_char = 'O';
			free(line);
			return (1);
		}
		if (!(ft_strcmp(line, "$$$ exec p2 : [./vgrynish.filler]")))
		{
			fdf->position = -1;
			fdf->enemy = 'O';
			fdf->my_char = 'X';
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

static int	robota_with_key(int key, t_key *fdf)
{
	if (key == 53)
		exit(0);
	if (fdf->score != 0 && key == 36)
	{
		ft_clear_fdf(fdf);
		if (!(init_map_viso(fdf)))
		{
			options(*fdf);
			fdf->score = 0;
		}
		else
		{
			mlx_destroy_image(fdf->mlx_ptr, (fdf->image).mlx_image);
			fdf->image.mlx_image = mlx_new_image(fdf->mlx_ptr, 2000, 2000);
			fdf->image.put_image = mlx_get_data_addr((fdf->image).mlx_image,
				&((fdf->image).bits_per_pixel), &((fdf->image).size_line),
												&((fdf->image).endian));
			draw_map(fdf);
			mlx_put_image_to_window(fdf->mlx_ptr, fdf->new_window,
									fdf->image.mlx_image, 200, 200);
		}
	}
	return (0);
}

int			main(void)
{
	t_key			fdf;
	void			*mlx_ptr;
	void			*new_window;
	t_image			image;

	mlx_ptr = mlx_init();
	new_window = mlx_new_window(mlx_ptr, 1500, 2000, "filler");
	image.mlx_image = mlx_new_image(mlx_ptr, 2000, 2000);
	image.put_image = mlx_get_data_addr(image.mlx_image,
	&(image.bits_per_pixel), &(image.size_line), &(image.endian));
	fdf.image = image;
	fdf.mlx_ptr = mlx_ptr;
	fdf.new_window = new_window;
	if (!fdf.position && !(init_players_viso(&fdf)))
		exit(0);
	if (!(init_map_viso(&fdf)))
		exit(0);
	ft_define_viso(&fdf);
	mlx_hook(new_window, 2, 5, robota_with_key, &fdf);
	options(fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.new_window,
							fdf.image.mlx_image, 200, 200);
	mlx_loop(mlx_ptr);
	return (0);
}
