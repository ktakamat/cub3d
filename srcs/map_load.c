/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:36:40 by apple             #+#    #+#             */
/*   Updated: 2024/09/14 16:30:32 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//にじ配列の幅と高さを取得する
void get_map_size(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nFailed to open file");
	width = 0;
	height = 0;
	// 最初の行を読み込む
	line = get_next_line(fd);
	if (line) { // lineがNULLでない場合のみ処理する
		width = ft_strlen(line);
		height++;
		free(line);

		// 2行目以降を読み込む
		while ((line = get_next_line(fd)) != NULL) {
			if (width < (int)ft_strlen(line))
				width = ft_strlen(line);
			height++;
			free(line);
		}
	}
	game->wid = width;
	game->hei = height;
	game->all_str = (char **)ft_calloc(sizeof(char *), height);
	close(fd);
}

//マップの文字列を読み込む
//この際、マップの情報は2次配列で保存する
void	map_load(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	size_t		i;

	if (!have_ber(filename))
		ft_exit_error("Error\nFailed to open file");
	fd = open(filename, O_RDONLY);
	printf("map load 1\n");
	get_map_size(filename, game);
	printf("map load 2\n");
	if (fd < 0)
		ft_exit_error("Error\nFailed to open file");
	//ここでmap_strにマップの情報を保存する
	i = 0;
	printf("game->hei = %zu\n", game->hei);
	printf("game->wid = %zu\n", game->wid);
	while (i < game->hei)
	{
		line = get_next_line(fd);
		if (line == NULL)
			ft_exit_error("Error\nFailed to read file");
		game->all_str[i] = ft_strdup(line);
		free(line);
		i++;
	}
	printf("map load 3\n");
	split_line(game);
	store_map(game);
	close(fd);
}
