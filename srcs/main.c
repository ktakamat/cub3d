/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:40:52 by ktakamat          #+#    #+#             */
/*   Updated: 2024/09/13 16:54:42 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cub3d(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	init_game(game);
	if (game->mlx == NULL)
		ft_exit_error("Error\nFailed to initialize mlx cub3D");
	map_load(argv[1], game);
	map_word_check(game);
	set_player(game);
	set_color(game);
	surround_wall(game);
	// print_game(game);
	
	
	set_game_tex(game);
	if (create_window(game) == ERROR)
		ft_exit_error("Error\nFailed to create window");
	create_wall(game);
	// libmlx(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press_hook, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release_hook, game);
	// mlx_hook(game->win, ClientMessage, 1L << 17, exit_game, &game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		ft_exit_error("Error\nInvalid number of arguments");
	ft_cub3d(argc, argv);
}