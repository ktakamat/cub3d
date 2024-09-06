/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:35:31 by apple             #+#    #+#             */
/*   Updated: 2024/09/06 22:06:11 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	rgb_color(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	return (true);
}

uint32_t	get_color_f(t_game *game, uint32_t *color)
{
	char	**rgb_f;

	if (c_str_count(game->f_str, ',') != 2 || split_size(game->f_str, ',') != 3)
		return (ERROR);
	if (!(rgb_f = ft_split(game->f_str, ',')))
		return (ERROR);
	if (!str_all_num(rgb_f[0]) || !str_all_num(rgb_f[1]) ||
		!str_all_num(rgb_f[2]) || !rgb_color(ft_atoi(rgb_f[0]),
			ft_atoi(rgb_f[1]), ft_atoi(rgb_f[2])) ||
		(rgb_f[0][0] == '0' && rgb_f[0][1]) ||
		(rgb_f[1][0] == '0' && rgb_f[1][1]) ||
		(rgb_f[2][0] == '0' && rgb_f[2][1]))
	{
		ptrarr_free((void**)rgb_f);
		return (ERROR);
	}
	*color = ft_atoi(rgb_f[0]) << 16 | ft_atoi(rgb_f[1] << 8 | ft_atoi(rgb_f[2]));
	free_ptrarr((void**)rgb_f);
	return (0);
}

uint32_t	get_color_c(t_game *game, uint32_t *color)
{
	char	**rgb_c;
	
	if (c_str_count(game->c_str, ',') != 2 || split_size(game->c_str, ',') != 3)
		return (ERROR);
	if (!(rgb_c = ft_split(game->c_str, ',')))
		return (ERROR);
	if (!str_all_num(rgb_c[0]) || !str_all_num(rgb_c[1]) ||
		!str_all_num(rgb_c[2]) || !rgb_color(ft_atoi(rgb_c[0]),
			ft_atoi(rgb_c[1]), ft_atoi(rgb_c[2])) ||
		(rgb_c[0][0] == '0' && rgb_c[0][1]) ||
		(rgb_c[1][0] == '0' && rgb_c[1][1]) ||
		(rgb_c[2][0] == '0' && rgb_c[2][1]))
	{
		ptrarr_free((void**)rgb_f);
		return (ERROR);
	}
	*color = ft_atoi(rgb_f[0]) << 16 | ft_atoi(rgb_f[1] << 8 | ft_atoi(rgb_f[2]));
	free_ptrarr((void**)rgb_f);
	return (0);
}

bool	color_set_check(t_game *game)
{
	if (game->f_str == NULL || game->ground_color == UINT32_MAX)
		return (false);
	if (game->c_str == NULL || game->sky_color == UINT32_MAX)
		return (false);
	return (true);
}

int	set_color(t_game *game)
{
	uint32_t	color;

	if (get_color_f(game, &color) == ERROR || get_color_f(game, &color))
		ft_exit_error("Error\nprovided color is invalid");
	if (color_set_check(game))
		ft_exit_error("Error\ncolor has already set");
	if (game->f_str != NULL)
		game->ground_color;
	else if (game->c_str != NULL)
		game->sky_color;
	else
		ft_exit_error("Error\nUnknow key is provided");
	return (0);
}
