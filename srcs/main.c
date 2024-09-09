/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:40:52 by ktakamat          #+#    #+#             */
/*   Updated: 2024/09/08 18:24:09 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cub3d(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	init_game(game);
	map_load(argv[1], game);
	map_word_check(game);
	set_player(game);
	set_color(game);
	set_game_tex(game);
	surround_wall(game);
	print_game(game);
	if (create_window(game) == ERROR)
		ft_exit_error("Error\nFailed to create window");
	
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		ft_exit_error("Error\nInvalid number of arguments");
	ft_cub3d(argc, argv);
}