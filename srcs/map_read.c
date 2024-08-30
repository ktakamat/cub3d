/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:36:40 by apple             #+#    #+#             */
/*   Updated: 2024/08/30 17:53:13 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


//初期化をするt_game
void	init_game(t_game *game)
{
	char **map_str;

	map_str = (char **)ft_calloc(sizeof(char *), 1);
	if (!map_str)
		ft_exit_error("Error\nFailed to allocate memory");
	game->map_str = map_str;
}

void	split_line(t_game *game)
{
	size_t	i;
	
	i = 0;
	while (i < game->hei)
	{
		if (game->all_str[i][0])
		{
			if (ft_strncmp(game->all_str[i], "NO", 2) == 0)
				game->no_str = ft_strdup(game->all_str[i]);
			if (ft_strncmp(game->all_str[i], "SO", 2) == 0)
				game->so_str = ft_strdup(game->all_str[i]);
			if (ft_strncmp(game->all_str[i], "WE", 2) == 0)
				game->we_str = ft_strdup(game->all_str[i]);
			if (ft_strncmp(game->all_str[i], "EA", 2) == 0)
				game->ea_str = ft_strdup(game->all_str[i]);
			if (ft_strncmp(game->all_str[i], "F", 1) == 0)
				game->f_str = ft_strdup(game->all_str[i]);
			if (ft_strncmp(game->all_str[i], "C", 1) == 0)
				game->c_str = ft_strdup(game->all_str[i]);
			
		}
		i++;
	}
}

//にじ配列の幅と高さを取得する
void get_map_size(char *filename, t_game *game)
{
    int fd;
    char *line;
    int width;
    int height;

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

//マップが1に囲まれているかを確認する
//アルゴリズムとして
void	map_check(t_game game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game.hei)
	{
		j = 0;
		while (j < game.wid)
		{
			if (i == 0 || i == game.hei - 1)
			{
				if (game.map_str[i][j] != '1')
					ft_exit_error("Error\nMap is not surrounded by 1");
			}
			else
			{
				if (j == 0 || j == game.wid - 1)
				{
					if (game.map_str[i][j] != '1')
						ft_exit_error("Error\nMap is not surrounded by 1");
				}
			}
			j++;
		}
		i++;
	}
}

//mapのもじれつが来るまでの文字列を取り出す
void	get_map_str(char *filename, t_game *game)
{
	size_t	map_hei;
	size_t	i;

	while (i)
}

//mapの文字列だけを取り出す
void	

//マップの文字列を読み込む
//この際、マップの情報は2次配列で保存する
void	map_load(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	size_t		i;

	fd = open(filename, O_RDONLY);
	printf("map load\n");
	get_map_size(filename, game);
	if (fd < 0)
		ft_exit_error("Error\nFailed to open file");
	//ここでmap_strにマップの情報を保存する
	i = 0;
	while (i < game->hei)
	{
		line = get_next_line(fd);
		if (line == NULL)
			ft_exit_error("Error\nFailed to read file");
		game->all_str[i] = ft_strdup(line);
		free(line);
		i++;
	}
	printf("map load 2\n");
	print_map(game);
	split_line(game);
	printf("game->no_str: %s\n", game->no_str);
	printf("game->so_str: %s\n", game->so_str);
	printf("game->we_str: %s\n", game->we_str);
	printf("game->ea_str: %s\n", game->ea_str);
	printf("game->height: %zu\n", game->hei);
	printf("game->width: %zu\n", game->wid);
	close(fd);
}

void	map_word_check(t_game *game)
{
	size_t	i;
	size_t	j;

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
				game->player_count++;
			j++;
		}
		i++;
	}
	if (game->player_count != 1)
		ft_exit_error("Error\nInvalid number of players");
}
