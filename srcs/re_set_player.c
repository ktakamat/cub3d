/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:46:46 by apple             #+#    #+#             */
/*   Updated: 2024/09/15 17:53:32 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player(t_game *game)
{
	double	old_dir_x;

	old_dir_x = game->player.dir.x;
	if (game->player.is_rotating != 0)
	{
		game->player.dir.x = game->player.dir.x * cos(game->player.is_rotating * PLAYER_HALF_ROTATE)
			- game->player.dir.y * sin(game->player.is_rotating * PLAYER_HALF_ROTATE);
		game->player.dir.y = old_dir_x * sin(game->player.is_rotating * PLAYER_HALF_ROTATE)
			+ game->player.dir.y * cos(game->player.is_rotating * PLAYER_HALF_ROTATE);
		game->player.plane.x = game->player.plane.x * cos(game->player.is_rotating * PLAYER_HALF_ROTATE)
			- game->player.plane.y * sin(game->player.is_rotating * PLAYER_HALF_ROTATE);
		game->player.plane.y = game->player.plane.x * sin(game->player.is_rotating * PLAYER_HALF_ROTATE)
			+ game->player.plane.y * cos(game->player.is_rotating * PLAYER_HALF_ROTATE);
		// printf("game->player.dir.x = %f\n", game->player.dir.x);
		// printf("game->player.dir.y = %f\n", game->player.dir.y);
		// printf("game->player.plane.x = %f\n", game->player.plane.x);
		// printf("game->player.plane.y = %f\n", game->player.plane.y);
	}
}

void	move_player(t_game *game)
{
	double	old_pos_x;
	double	old_pos_y;

	if (game->player.is_moving)
	{
		old_pos_x = game->player.pos.x;
		game->player.pos.x += game->player.dir.x * game->player.is_moving * MOVE_PLAYER_SPEED;
		if (game->map_str[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
			game->player.pos.x = old_pos_x;
		old_pos_y = game->player.pos.y;
		game->player.pos.y += game->player.dir.y * game->player.is_moving * MOVE_PLAYER_SPEED;
		if (game->map_str[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
			game->player.pos.y = old_pos_y;
	}
}

void	slide_player(t_game *game)
{
	double	old_pos_x;
	double	old_pos_y;

	if (game->player.is_sidling)
	{
		// printf("game->player.is_sidling = %d\n", game->player.is_sidling);
		old_pos_x = game->player.pos.x;
		game->player.pos.x += game->player.dir.y * game->player.is_sidling * MOVE_PLAYER_SPEED;
		if (game->map_str[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
			game->player.pos.x = old_pos_x;
		old_pos_y = game->player.pos.y;
		game->player.pos.y -= game->player.dir.x * game->player.is_sidling * MOVE_PLAYER_SPEED;
		if (game->map_str[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
			game->player.pos.y = old_pos_y;
	}
}

void	re_set_player(t_game *game)
{
	rotate_player(game);
	move_player(game);
	slide_player(game);
}
