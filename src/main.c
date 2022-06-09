/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:59:25 by donghyeon         #+#    #+#             */
/*   Updated: 2022/06/09 09:29:29 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		exit_game(void)
{
	ft_exit("[Bye] Red button is pressed");
	return (0);
}

void	init_cub(t_info *cub, char *arg)
{
	ft_memset(cub, 0, sizeof(t_info));
	cub->ele.floor = -1;
	cub->ele.ceiling = -1;
	cub->ele.render_x = 1920;
	cub->ele.render_y = 1080;
	cub->width = cub->ele.render_x;
	cub->height = cub->ele.render_y;
	if (!ft_isformat(arg, ".cub"))
		ft_exit("[ERROR] Invalid .cub file format");
	if ((cub->fd = open(arg, O_RDONLY)) == -1)
		ft_exit("[ERROR] Fail to open .cub file");
}

int	main(int argc, char **argv)
{
	t_info	cub;

	if (argc != 2)
	{
		printf("Please write ./cub3D map.cub\n");
		return (0);
	}
	init_cub(&cub, argv[1]);
	read_cub_element_lines(&cub);
	read_cub_map_lines(&cub);
	valid_cub(&cub);
	set_cub(&cub);
	start_game(&cub);
	return (0);
}
