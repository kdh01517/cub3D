/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:40:46 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/06 02:55:26 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_img
{
	void			*ptr;
	int				*data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			distance;
}					t_sprite;

typedef struct s_sprite_ray
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				v_move_screen;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
}					t_sprite_ray;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start_y;
	int				draw_end_y;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
}					t_ray;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	char			spawning_orientation;
}					t_player;

typedef struct s_element
{
	int				render_x;
	int				render_y;
	char			*xpm_path[5];
	int				tex[5][TEX_HEIGHT * TEX_WIDTH];
	int				floor;
	int				ceiling;
}					t_element;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	int				fd;
	t_element		ele;
	int				width;
	int				height;
	t_list			*map_lines;
	char			**map;
	int				map_width;
	int				map_height;
	t_player		player;
	int				**buf;
	double			*z_buf;
	t_img			img;
	int				num_sprite;
	t_sprite		*sprite;
	t_ray			ray;
	t_sprite_ray	s_ray;
}					t_cub;

#endif