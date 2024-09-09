/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:21:15 by machi             #+#    #+#             */
/*   Updated: 2024/09/09 16:46:56 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void initialized_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
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

void	wall_vis(t_game *game, t_ray *ray, t_wall *wall_vis)
{
	//高さの基本ベースから距離によっての壁の高さを決める
	wall_vis->line_hei = (int)(game->height_base / ray->perp_wall_dist);
	wall_vis->draw_start = -wall_vis->line_hei / 2 + SCREEN_HEIGHT / 2;
	if (wall_vis->draw_start < 0)
		wall_vis->draw_start = 0;
	wall->draw_end = wall_vis->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall_vis->draw_end >= SCREEN_HEIGHT)
		wall_vis->draw_end = SCREEN_HEIGHT - 1;
	//ifのどこの側面に光線があたったかyかx
	//それで壁上のどの部分をテクスチャで描画するか決定する
	if (ray.side == 0)
		wall_vis->wall_x = game->player.pos.y + ray.perp_wall_dist * ray.dir.y;
	else
		wall_vis->wall_x = game->player.pos.x + ray.perp_wall_dist * ray.dir.x;
	wall_vis->wall_x -= floor(wall_vis->wall_x);
	wall_vis->texture_z = (int)(wall_vis->wall_x);
	if ((ray.side == 0 && ray.dir.x < 0) || (ray.side == 1 && ray.dir.y > 0))
		wall_vis->texture_x = ray.tex->width - wall_vis->texture_x - 1;
	wall_vis->step = 1.0 * ray.tex->height / (double)wall_vis->line_hei;
}

static void	draw_per_line(t_game *game, t_ray ray, t_wall *wall_vis,
			int x)


void	create_wall(t_game *game)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	x = 0;
	while (x < SCREEN_HEIGHT)
	{
		initialized_ray(game, &ray, x);
		simulate_ray(game, &ray);
		game->dist_buffer[x] = ray.perp_wall_dist;
		wall_vis(game, ray, &wall, x);
		
	}
}
