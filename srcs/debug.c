/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:52 by apple             #+#    #+#             */
/*   Updated: 2024/08/30 15:16:55 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void print_map(t_game *game)
{
    printf("Map (width: %zu, height: %zu):\n", game->wid, game->hei);
    for (size_t i = 0; i < game->hei; i++) {
        printf("%s", game->map_str[i]);
    }
}