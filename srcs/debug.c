/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:52 by apple             #+#    #+#             */
/*   Updated: 2024/09/06 19:30:58 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void print_map(t_game *game)
{
    printf("Map (width: %zu, height: %zu):\n", game->wid, game->hei);
    for (size_t i = 0; i < game->hei; i++) {
        printf("%s", game->all_str[i]);
    }
}

void    print_map_str(t_game *game)
{
    printf("Map (width: %zu, height: %zu):\n", game->wid, game->hei);
    for (size_t i = 0; i < game->hei; i++) {
        printf("%s", game->map_str[i]);
    }
    printf("\n");
}

void    print_game(t_game *game)
{
    printf("Game:\n");
    printf("mlx: %p\n", game->mlx);
    printf("img: %p\n", game->img.img);
    printf("hei: %zu\n", game->hei);
    printf("wid: %zu\n", game->wid);
    printf("str_line: %s\n", game->str_line);
    printf("player_count: %d\n", game->player_count);
    printf("all_str: %p\n", game->all_str);
    printf("no_str: %s\n", game->no_str);
    printf("so_str: %s\n", game->so_str);
    printf("we_str: %s\n", game->we_str);
    printf("ea_str: %s\n", game->ea_str);
    printf("f_str: %s\n", game->f_str);
    printf("c_str: %s\n", game->c_str);
    print_map_str(game);
    printf("player: %p\n", &game->player);
    printf("no_tex: %p\n", game->no_tex.img);
    printf("so_tex: %p\n", game->so_tex.img);
    printf("we_tex: %p\n", game->we_tex.img);
    printf("ea_tex: %p\n", game->ea_tex.img);
    printf("running: %d\n", game->running);
}
