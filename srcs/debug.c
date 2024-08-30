/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:52 by apple             #+#    #+#             */
/*   Updated: 2024/08/30 17:38:02 by ktakamat         ###   ########.fr       */
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
