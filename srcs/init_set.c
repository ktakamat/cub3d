/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:06:25 by apple             #+#    #+#             */
/*   Updated: 2024/09/12 21:09:36 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//初期化をするt_game
void	init_game(t_game *game)
{
	char 	**map_str;

	// game = (t_game *x)ft_calloc(sizeof(t_game), 1);
	if (!game)
		ft_exit_error("Error\nFailed to allocate memory");
	game->dist_buffer = (double *)ft_calloc(sizeof(double), SCREEN_WIDTH);
	if (!game->dist_buffer)
		ft_exit_error("Error\nFailed to allocate memory");
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit_error("Error\nFailed to initialize mlx");
}

void	set_player(t_game *game)
{
	if (game->map_str[game->player.y][game->player.x] == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.plane.x = -1 * tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.x = tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = -1 * tan(change_pi(FOV / 2));
	}
	game->player.pos.x = game->player.x + 0.5;
	game->player.pos.y = game->player.y + 0.5;
}

void	set_game_tex(t_game *game)
{

	game->no_tex.img = mlx_xpm_file_to_image(game->mlx, game->no_str, &game->no_tex.wid, &game->no_tex.hei);
	if (!game->no_tex.img)
		ft_exit_error("Error\nFailed to set texture 1");

	game->so_tex.img = mlx_xpm_file_to_image(game->mlx, game->so_str, &game->so_tex.wid, &game->so_tex.hei);
	if (!game->so_tex.img)
		ft_exit_error("Error\nFailed to set texture 2");

	game->we_tex.img = mlx_xpm_file_to_image(game->mlx, game->we_str, &game->we_tex.wid, &game->we_tex.hei);
	if (!game->we_tex.img)
		ft_exit_error("Error\nFailed to set texture 3");

	game->ea_tex.img = mlx_xpm_file_to_image(game->mlx, game->ea_str, &game->ea_tex.wid, &game->ea_tex.hei);
	if (!game->ea_tex.img)
		ft_exit_error("Error\nFailed to set texture 4");

	game->no_tex.addr = mlx_get_data_addr(game->no_tex.img, &game->no_tex.bits_per_pixel, &game->no_tex.line_len, &game->no_tex.endian);
	if (!game->no_tex.addr)
		ft_exit_error("Error\nFailed to set texture");

	game->so_tex.addr = mlx_get_data_addr(game->so_tex.img, &game->so_tex.bits_per_pixel, &game->so_tex.line_len, &game->so_tex.endian);
	if (!game->so_tex.addr)
		ft_exit_error("Error\nFailed to set texture");

	game->we_tex.addr = mlx_get_data_addr(game->we_tex.img, &game->we_tex.bits_per_pixel, &game->we_tex.line_len, &game->we_tex.endian);
	if (!game->we_tex.addr)
		ft_exit_error("Error\nFailed to set texture");
	
	game->ea_tex.addr = mlx_get_data_addr(game->ea_tex.img, &game->ea_tex.bits_per_pixel, &game->ea_tex.line_len, &game->ea_tex.endian);
	if (!game->ea_tex.addr)
		ft_exit_error("Error\nFailed to set texture");
}
