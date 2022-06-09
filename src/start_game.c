/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:04:59 by haseo             #+#    #+#             */
/*   Updated: 2022/06/09 09:15:42 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move_forward_backward(t_info *cub, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = cub->map[(int)player->pos_y]
	[(int)(player->pos_x + player->dir_x * move_speed)];
	y = cub->map[(int)(player->pos_y + player->dir_y * move_speed)]
	[(int)player->pos_x];
	if (x != WALL)
		player->pos_x += player->dir_x * move_speed;
	if (y != WALL)
		player->pos_y += player->dir_y * move_speed;
}

void	move_left_right(t_info *cub, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = cub->map[(int)player->pos_y]
	[(int)(player->pos_x + player->dir_y * move_speed)];
	y = cub->map[(int)(player->pos_y + -player->dir_x * move_speed)]
	[(int)player->pos_x];
	if (x != WALL)
		player->pos_x += player->dir_y * move_speed;
	if (y != WALL)
		player->pos_y += -player->dir_x * move_speed;
}

void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
		+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}

int	handle_key(int key, t_info *cub)
{
	if (key == KEY_W)
		move_forward_backward(cub, &cub->player, cub->player.move_speed);
	if (key == KEY_S)
		move_forward_backward(cub, &cub->player, -cub->player.move_speed);
	if (key == KEY_A)
		move_left_right(cub, &cub->player, cub->player.move_speed);
	if (key == KEY_D)
		move_left_right(cub, &cub->player, -cub->player.move_speed);
	if (key == KEY_LEFT)
		rotate_player(&cub->player, -cub->player.rot_speed);
	if (key == KEY_RIGHT)
		rotate_player(&cub->player, cub->player.rot_speed);
	if (key == KEY_ESC)
		ft_exit("[Bye] Exit key is pressed");
	return (0);
}

void	start_game(t_info *cub)
{
	cub->img.ptr = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.ptr,
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3D");
	mlx_hook(cub->win, X_EVENT_KEY_PRESS, 0, &handle_key, cub);
	mlx_hook(cub->win, X_EVENT_KEY_EXIT, 0, &exit_game, cub);
	mlx_loop_hook(cub->mlx, &raycast, cub);
	mlx_loop(cub->mlx);
}
