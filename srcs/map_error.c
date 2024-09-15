/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:01:12 by machi             #+#    #+#             */
/*   Updated: 2024/09/15 15:59:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//構造体のメンバーに適切に格納されているのかを確認する
void	check_game_member(t_game *game)
{
	if (game->no_str == NULL || game->so_str == NULL || game->we_str == NULL
		|| game->ea_str == NULL || game->f_str == NULL || game->c_str == NULL)
		ft_exit_error("Error\nFailed to read file");
	if (game->wid == 0 || game->hei == 0)
		ft_exit_error("Error\nFailed to read file");
}

void	map_word_check(t_game *game)
{
	size_t	i;
	size_t	j;

	if (!game->map_str)
		ft_exit_error("Error\nMap not initialized");
	i = 0;
	while(i < game->hei)
	{
		j = 0;
		while(game->map_str[i][j])
		{
			if (game->map_str[i][j] != 'N' && game->map_str[i][j] != 'S' 
				&& game->map_str[i][j] != 'E' && game->map_str[i][j] != 'W'
				&& game->map_str[i][j] != '0' && game->map_str[i][j] != '1'
				&& game->map_str[i][j] != ' ' && game->map_str[i][j] != '\n')
				ft_exit_error("Error\nFailed to read file");
			if (game->map_str[i][j] == 'N' || game->map_str[i][j] == 'S' 
				|| game->map_str[i][j] == 'E' || game->map_str[i][j] == 'W')
				{
					game->player_count++;
					game->player.x = j;
					game->player.y = i;
					printf("game->player.xddd = %d\n", game->player.x);
					printf("game->player.y ddd= %d\n", game->player.y);
				}
			j++;
		}
		i++;
	}
	if (game->player_count != 1)
		ft_exit_error("Error\nInvalid number of players");
	check_game_member(game);
}
