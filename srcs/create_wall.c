/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:21:15 by machi             #+#    #+#             */
/*   Updated: 2024/09/12 18:40:01 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void initialized_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
	// printf("game->player.x: %d\n", game->player.x);
	// printf("game->player.y: %d\n", game->player.y);
	// printf("game->player.plane.x: %f\n", game->player.plane.x);
	// printf("game->player.plane.y: %f\n", game->player.plane.y);
	// printf("ray->camera_x: %f\n", ray->camera_x);
	// printf("ray->dir.x: %f\n", ray->dir.x);
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
		ray->tex = (ray->step_x > 0) ? &game->we_tex : &game->ea_tex;
	else
		ray->tex = (ray->step_y > 0) ? &game->so_tex : &game->no_tex;
}

void	wall_vis(t_game *game, t_ray ray, t_wall *wall_vis)
{
	//高さの基本ベースから距離によっての壁の高さを決める
	wall_vis->line_hei = (int)(game->height_base / ray.perp_wall_dist);
	wall_vis->draw_start = -wall_vis->line_hei / 2 + SCREEN_HEIGHT / 2;
	if (wall_vis->draw_start < 0)
		wall_vis->draw_start = 0;
	wall_vis->draw_end = wall_vis->line_hei / 2 + SCREEN_HEIGHT / 2;
	if (wall_vis->draw_end >= SCREEN_HEIGHT)
		wall_vis->draw_end = SCREEN_HEIGHT - 1;
	//ifのどこの側面に光線があたったかyかx
	//それで壁上のどの部分をテクスチャで描画するか決定する
	if (ray.side == 0)
		wall_vis->wall_x = game->player.pos.y + ray.perp_wall_dist * ray.dir.y;
	else
		wall_vis->wall_x = game->player.pos.x + ray.perp_wall_dist * ray.dir.x;
	wall_vis->wall_x -= floor(wall_vis->wall_x);
	wall_vis->texture_x = (int)(wall_vis->wall_x);
	if ((ray.side == 0 && ray.dir.x < 0) || (ray.side == 1 && ray.dir.y > 0))
		wall_vis->texture_x = ray.tex->wid - wall_vis->texture_x - 1;
	if (ray.tex->hei == 0)
		ft_exit_error("Error\nTexture height is 0");
	wall_vis->step = 1.0 * ray.tex->hei / (double)wall_vis->line_hei;
}

void		my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len +
		x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	draw_per_line(t_game *game, t_ray ray, t_wall *wall_vis,
			int x)
{
	int			y;
	uint32_t	color;

	wall_vis->texture_pos_y = (wall_vis->draw_start - SCREEN_HEIGHT / 2
		+ wall_vis->line_hei / 2) * wall_vis->step;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		//game->imgがNULLの場合はエラーを出力する
		if (game->img.img == NULL)
			ft_exit_error("Error\nimg Failed to initialize mlx cub3D");
		if (y <= SCREEN_HEIGHT / 2)
			my_mlx_pixel_put(&(game->img), x, y, game->sky_color);
		else
			my_mlx_pixel_put(&(game->img), x, y, game->ground_color);
		if (y >= wall_vis->draw_start && y < wall_vis->draw_end)
		{
			wall_vis->texture_y = (int)wall_vis->texture_pos_y;
			if (wall_vis->texture_y >= ray.tex->hei)
				wall_vis->texture_y = ray.tex->hei - 1;
			wall_vis->texture_pos_y += wall_vis->step;
			color = get_color(*ray.tex, wall_vis->texture_x,
				wall_vis->texture_y);
			my_mlx_pixel_put(&(game->img), x, y, color);
		}
		y++;
	}
}

void	create_wall(t_game *game)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		initialized_ray(game, &ray, x);
		simulate_ray(game, &ray);
		game->dist_buffer[x] = ray.perp_wall_dist;
		// printf("game->dist_buffer[%d]: %f\n", x, game->dist_buffer[x]);
		wall_vis(game, ray, &wall);
		draw_per_line(game, ray, &wall, x);
		x++;
	}
}
