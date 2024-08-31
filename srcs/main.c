/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:40:52 by ktakamat          #+#    #+#             */
/*   Updated: 2024/08/31 19:36:47 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cub3d(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	// map_read(argv[1], game);
	init_game(game);
	//マップの情報を書き出す
	map_load(argv[1], game);
	//マップがN,E,W,S,0,1,space,\nでなりたっているかを確認し、playerの数をカウントする
	map_word_check(game);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		ft_exit_error("Error\nInvalid number of arguments");
	ft_cub3d(argc, argv);
}