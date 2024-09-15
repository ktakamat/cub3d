/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:32:45 by apple             #+#    #+#             */
/*   Updated: 2024/09/15 17:24:14 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.is_moving = 1;
	if (keycode == KEY_S)
		game->player.is_moving = -1;
	if (keycode == KEY_A)
		game->player.is_sidling = -1;
	if (keycode == KEY_D)
		game->player.is_sidling = 1;
	if (keycode == KEY_LEFT)
		game->player.is_rotating = -1;
	if (keycode == KEY_RIGHT)
		game->player.is_rotating = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int key_release_hook(int keycode, t_game *game)
{
	printf("keycode = %d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_S)
		game->player.is_moving = 0;
	if (keycode == KEY_A || keycode == KEY_D)
		game->player.is_sidling = 0;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game->player.is_rotating = 0;
	return (0);
}

int		main_loop(t_game *game)
{
	clear_img(&(game->img));
	re_set_player(game);
	create_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
