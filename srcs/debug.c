/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:52 by apple             #+#    #+#             */
/*   Updated: 2024/09/12 19:23:52 by apple            ###   ########.fr       */
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

void	print_rgb(char **rgb)
{
	printf("R: %s\n", rgb[0]);
	printf("G: %s\n", rgb[1]);
	printf("B: %s\n", rgb[2]);
}

void	print_texture(t_game *game)
{
	printf("Texture:\n");
	printf("no_tex: %p\n", game->no_tex.img);
	printf("so_tex: %p\n", game->so_tex.img);
	printf("we_tex: %p\n", game->we_tex.img);
	printf("ea_tex: %p\n", game->ea_tex.img);
	
	printf("no_tex addr: %p\n", game->no_tex.addr);
	printf("so_tex addr: %p\n", game->so_tex.addr);
	printf("we_tex addr: %p\n", game->we_tex.addr);
	printf("ea_tex addr: %p\n", game->ea_tex.addr);
}

void	debug_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	libmlx(t_game *game)
{
	printf("libmlx\n");
	void *mlx;
	void *mlx_win;
	int x = 5;
	int y = 5;
	int color = 0x00FF0000; // 赤
	if (game->mlx == NULL)
		ft_exit_error("Error\nFailed to initialize mlx cub3D");
	mlx = game->mlx;
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_len, &game->img.endian);
	printf("game->no_tex.img: %p\n", game->no_tex.img);
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "raycaster");
	// debug_my_mlx_pixel_put(game->img.img, x, y, color); // 不要
	mlx_pixel_put(mlx, mlx_win, x, y, color); 
	mlx_put_image_to_window(mlx, mlx_win, game->img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, game->no_tex.img, 0, 0);
	mlx_loop(mlx);
}
