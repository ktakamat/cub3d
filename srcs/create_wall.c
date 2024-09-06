/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:21:15 by machi             #+#    #+#             */
/*   Updated: 2024/09/06 21:24:54 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void initialized_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)MAP_WINDTH - 1;
	ray->dir.x = game->player.x + game->player.plane.x * ray->camera_x; //
	ray->dir.y = game->player.y + game->player.plane.y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->delta_dist_x = (1 / ray->dir.x) < 0 ? -1 * (1 / ray->dir.x) : (1 / ray->dir.x);
	ray->delta_dist_y = (1 / ray->dir.y) < 0 ? -1 * (1 / ray->dir.y) : (1 / ray->dir.y);
	ray->step_x = ray->dir.x < 0 ? -1 : 1;
	ray->side_dist_x = ray->dir.x < 0 ? (game->player.pos.x - ray->map_x) * ray->delta_dist_x : (ray->map_x + 1.0 - game->player.pos.x) * ray->delta_dist_x;
	ray->step_y = ray->dir.y < 0 ? -1 : 1;
	ray->side_dist_y = ray->dir.y < 0 ? (game->player.pos.y - ray->map_y) * ray->delta_dist_y :(ray->map_y + 1.0 - game->player.pos.y) * ray->delta_dist_y;
}

void	simulate_ray(t_game *game, t_ray *ray)
{
	while (game->map_str[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos.x + (1 - ray->step_x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos.y + (1 - ray->step_y) / 2) / ray->dir.y;
	//game->we_strをあとで変更する
	if (ray->side == 0)
		ray->tex = (ray->step_x > 0) ? &game->we_str : &game->ea_str;
	else
		ray->tex = (ray->step_y > 0) ? &game->so_str : &game->no_str;
}

void	wall_vis(t_game *game, t_ray *ray)
{
	
}