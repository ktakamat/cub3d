/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:58:17 by apple             #+#    #+#             */
/*   Updated: 2024/09/12 21:26:30 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	new_window(t_game *game)
{
	if (!(game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
		"cub3D")))
		ft_exit_error("Error\ncreating window is failed");
	return (0);
}

int	create_window(t_game *game)
{
	double	plane_len;

	if (new_window(game) == ERROR)
		return (ERROR);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
		&game->img.line_len, &game->img.endian);
	if (game->img.img == NULL)
		ft_exit_error("Error\nimg Failed to initialize mlx img\n");
	game->img.wid = SCREEN_WIDTH;
	game->img.hei = SCREEN_HEIGHT;
	game->tex_wid = game->no_tex.wid;
	game->tex_hei = game->no_tex.hei;
	plane_len = vec_len(game->player.plane);
	game->height_base = (double)SCREEN_WIDTH * (1 / (2 * plane_len));
	mlx_do_key_autorepeaton(game->mlx);
	return (0);
}
