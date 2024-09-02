/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:41:31 by ktakamat          #+#    #+#             */
/*   Updated: 2024/09/02 16:12:58 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	surround_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->hei_map)
	{
		j = 0;
		while (j < game->wid)
		{
			if (game->map_str[i][j] == '0')
			{
				//一番上か一番下に0がある場合
				if (i == 0 || j == 0)
					ft_exit_error("Error\nMap is not surrounded by 1");
				//一番左か一番右に0がある場合
				else if (i == game->hei_map - 1 || game->map_str[i][j + 1] == '\n')
					ft_exit_error("Error\nMap is not surrounded by 2");
				//
				else if (game->map_str[i][j - 1] == ' ' || game->map_str[i][j + 1] == ' ')
					ft_exit_error("Error\nMap is not surrounded by 3");
				//一番左か一番右に0がある場合
				else if (game->map_str[i + 1][j] == ' ' || game->map_str[i - 1][j] == ' ')
					ft_exit_error("Error\nMap is not surrounded by 4");
			}
			j++;
		}
		i++;
	}
}