/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:19 by machi             #+#    #+#             */
/*   Updated: 2024/09/09 16:55:47 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"\

void	split_line(t_game *game)
{
	size_t	i;
	
	i = 0;
	while (i < game->hei)
	{
		if (game->all_str[i][0])
		{
			if (ft_strncmp(game->all_str[i], "NO ", 3) == 0)
				game->no_str = ft_strdup(game->all_str[i] + 3);
			if (ft_strncmp(game->all_str[i], "SO ", 3) == 0)
				game->so_str = ft_strdup(game->all_str[i] + 3);
			if (ft_strncmp(game->all_str[i], "WE ", 3) == 0)
				game->we_str = ft_strdup(game->all_str[i] + 3);
			if (ft_strncmp(game->all_str[i], "EA ", 3) == 0)
				game->ea_str = ft_strdup(game->all_str[i] + 3);
			if (ft_strncmp(game->all_str[i], "F ", 2) == 0)
				game->f_str = ft_strdup(game->all_str[i] + 2);
			if (ft_strncmp(game->all_str[i], "C ", 2) == 0)
				game->c_str = ft_strdup(game->all_str[i] + 2);
		}
		i++;
	}
}

//mapの文字列だけを取り出す
void	store_map(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	height;
	int		count;
	int		flag;

	i = 0;
	count = 0;
	flag = 0;
	height = game->hei;
	while (i < game->hei)
	{
		if (game->all_str[i][0])
		{
			if (game->all_str[i][0] != ' ' && game->all_str[i][0] != '1'
				&& game->all_str[i][0] != '0')
			{
				count++;
				i++;
			}
			if (game->all_str[i][0] == ' ' || game->all_str[i][0] == '1'
				|| game->all_str[i][0] == '0')
			{
				flag = 1;
				j = 0;
				while (game->all_str[i][j])
				{
					if (game->all_str[i][j] != ' ' && game->all_str[i][j] != '1'
					&& game->all_str[i][j] != '0' && game->all_str[i][j] != 'N'
					&& game->all_str[i][j] != 'S' && game->all_str[i][j] != 'E'
					&& game->all_str[i][j] != 'W' && game->all_str[i][j] != '\n')
					{
						ft_exit_error("Error\ndInvalid map");
					}
					j++;
				}
				i++;
			}
		}
	}
	if (flag == 1)
	{
		game->map_str = (char **)ft_calloc(sizeof(char *), height - count + 1);
		if (!game->map_str)
			ft_exit_error("Error\nFailed to allocate memory");
		i = 0;
		j = 0;
		game->hei = height - count;
		while (i < height)
		{
			if (game->all_str[i][0] == ' ' || game->all_str[i][0] == '1'
				|| game->all_str[i][0] == '0')
			{
				game->map_str[j] = ft_strdup(game->all_str[i]);
				j++;
			}
			i++;
		}
		game->map_str[j] = NULL;
	}
	else
		ft_exit_error("Error\nInvalid map");
}
