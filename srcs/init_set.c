/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:06:25 by apple             #+#    #+#             */
/*   Updated: 2024/09/06 19:21:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

//初期化をするt_game
void	init_game(t_game *game)
{
	char 	**map_str;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		ft_exit_error("Error\nFailed to allocate memory");
}

void	set_player(t_game *game)
{
	if (game->map_str[game->player.y][game->player.x] == 'N')
	{
		game->player.dir.x = -1;
		game->player.plane.x = tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'S')
	{
		game->player.dir.x = 1;
		game->player.plane.x = -1 * tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'E')
	{
		game->player.dir.y = 1;
		game->player.plane.x = tan(change_pi(FOV / 2));
	}
	else if (game->map_str[game->player.y][game->player.x] == 'W')
	{
		game->player.dir.y = -1;
		game->player.plane.x = -1 * tan(change_pi(FOV / 2));
	}
	game->player.pos.x = game->player.x + 0.5;
	game->player.pos.y = game->player.y + 0.5;
}

void	set_game_tex(t_game *game)
{
	game->no_tex.img = mlx_xpm_file_to_image(game->mlx, game->no_str, &game->no_tex.wid, &game->no_tex.hei);
	game->so_tex.img = mlx_xpm_file_to_image(game->mlx, game->so_str, &game->so_tex.wid, &game->so_tex.hei);
	game->we_tex.img = mlx_xpm_file_to_image(game->mlx, game->we_str, &game->we_tex.wid, &game->we_tex.hei);
	game->ea_tex.img = mlx_xpm_file_to_image(game->mlx, game->ea_str, &game->ea_tex.wid, &game->ea_tex.hei);
}
