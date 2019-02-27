/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:59:32 by vgrynish          #+#    #+#             */
/*   Updated: 2018/12/17 16:59:32 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "mlx.h"

typedef struct			s_filler
{
	int					position;
	int					map_x;
	int					map_y;
	int					piece_x;
	int					piece_y;
	char				enemy;
	char				my_char;
	char				**map;
	char				**piece;
	int					best_len;
	int					best_x;
	int					best_y;
}						t_filler;

typedef struct			s_image
{
	void				*mlx_image;
	char				*put_image;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_coordinat
{
	int					x;
	int					y;
	int					color;
}						t_coordinat;

typedef struct			s_key
{
	t_image				image;
	int					score;
	int					my_score;
	int					enemy_score;
	void				*mlx_ptr;
	void				*new_window;
	int					zoom;
	int					color;
	int					position;
	int					map_x;
	int					map_y;
	char				enemy;
	char				my_char;
	char				**map;
}						t_key;

int						init_piece(t_filler *filler);
int						init_map(t_filler *filler);
void					find_best_position(t_filler filler);
void					draw_map(t_key *fdf);
void					draw_line(t_coordinat start, t_coordinat end,
								t_key fdf);
void					plus_line(int *i, int *x2, int *y2, int x);
void					plus_dot(char **piece, int *x2, int *i);
int						plus_star(t_filler filler, int *only_one, int y, int x);
void					plus_best_position(t_filler *filler, int len,
										int x, int y);
int						init_map_viso(t_key *fdf);
void					ft_define_viso(t_key *fdf);
void					ft_clear_fdf(t_key *fdf);
void					options(t_key fdf);
int						check_big(t_filler filler, int y, int x);

#endif
