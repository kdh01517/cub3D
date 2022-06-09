/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:40:46 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/09 09:29:08 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define GL_SILENCE_DEPRECATION
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define NORTH				0
# define SOUTH				1
# define EAST				2
# define WEST				3
# define FLOOR				5
# define CEILING			6
# define MAP				7
# define EMPTY				'0'
# define WALL				'1'
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define TEX_WIDTH			64
# define TEX_HEIGHT 		64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

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
	int				floor;
	int				ceiling;
	char			*xpm_path[4];
	int				tex[4][TEX_HEIGHT * TEX_WIDTH];
}					t_element;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	int				fd;
	int				width;
	int				height;
	char			**map;
	int				map_width;
	int				map_height;
	int				**buf;
	double			*z_buf;
	t_list			*map_lines;
	t_player		player;
	t_element		ele;
	t_img			img;
	t_ray			ray;
}					t_info;

void				init_cub(t_info *cub, char *arg);
int					exit_game(void);
void				read_cub_element_lines(t_info *cub);
void				read_cub_map_lines(t_info *cub);
int					raycast(t_info *cub);
void				valid_element_lines(char *word, int cnt_word);
void				valid_cub(t_info *cub);
void				set_cub(t_info *cub);

void				start_game(t_info *cub);
void				rotate_player(t_player *player, double rot_speed);

void				init_ray(t_info *cub, t_player *p, t_ray *ray, int x);
void				calc_step_sidedist(t_player *p, t_ray *ray);
void				perform_dda(t_info *cub, t_ray *ray);

void				calc_wall_distance(t_player *p, t_ray *ray);
void				calc_wall_height(t_info *cub, t_ray *ray);
void				set_wall_tex_x(t_player *player, t_ray *ray);
void				set_wall_tex_y(t_info *cub, t_ray *ray, int x);

#endif