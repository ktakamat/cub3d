/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:19 by machi             #+#    #+#             */
/*   Updated: 2024/09/15 20:38:40 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"\

// ft_strdup 関数は、文字列をコピーする際に、元の文字列の末尾にある改行文字も含めてコピーしてしまうため、問題が発生しています。

// この問題を解決するには、ft_strdup を使う代わりに、ft_strtrim 関数を使って改行文字を削除してからコピーする必要があります。ft_strtrim 関数は、指定された文字列から先頭と末尾の指定された文字を削除する関数です。

// 修正後の split_line 関数は以下のようになります。

void	split_line(t_game *game)
{
	size_t	i;
	char	*trim_str;
	int		no_count = 0; // NOの出現回数をカウント
	int		so_count = 0; // SOの出現回数をカウント
	int		we_count = 0; // WEの出現回数をカウント
	int		ea_count = 0; // EAの出現回数をカウント
	int		f_count = 0;  // Fの出現回数をカウント
	int		c_count = 0;  // Cの出現回数をカウント

	i = 0;
	while (i < game->hei)
	{
		if (game->all_str[i][0])
		{
			if (ft_strncmp(game->all_str[i], "NO ", 3) == 0)
			{
				no_count++;
				if (no_count > 1)
					ft_exit_error("Error\nDuplicate NO identifier."); // エラー処理
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->no_str = ft_strdup(trim_str);
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "SO ", 3) == 0)
			{
				so_count++;
				if (so_count > 1)
					ft_exit_error("Error\nDuplicate SO identifier."); // エラー処理
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->so_str = ft_strdup(trim_str);
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "WE ", 3) == 0)
			{
				we_count++;
				if (we_count > 1)
					ft_exit_error("Error\nDuplicate WE identifier."); // エラー処理
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->we_str = ft_strdup(trim_str);
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "EA ", 3) == 0)
			{
				ea_count++;
				if (ea_count > 1)
					ft_exit_error("Error\nDuplicate EA identifier."); // エラー処理
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->ea_str = ft_strdup(trim_str);
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "F ", 2) == 0)
			{
				f_count++;
				if (f_count > 1)
					ft_exit_error("Error\nDuplicate F identifier."); // エラー処理
				game->f_str = ft_strdup(game->all_str[i] + 2);
			}
			else if (ft_strncmp(game->all_str[i], "C ", 2) == 0)
			{
				c_count++;
				if (c_count > 1)
					ft_exit_error("Error\nDuplicate C identifier."); // エラー処理
				game->c_str = ft_strdup(game->all_str[i] + 2);
			}
		}
		i++;
	}
}
// void	split_line(t_game *game)
// {
// 	size_t	i;
// 	char	*trim_str;

// 	i = 0;
// 	while (i < game->hei)
// 	{
// 		if (game->all_str[i][0])
// 		{
// 			if (ft_strncmp(game->all_str[i], "NO ", 3) == 0)
// 			{
// 				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
// 				game->no_str = ft_strdup(trim_str);
// 				free(trim_str);
// 			}
// 			else if (ft_strncmp(game->all_str[i], "SO ", 3) == 0)
// 			{
// 				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
// 				game->so_str = ft_strdup(trim_str);
// 				free(trim_str);
// 			}
// 			else if (ft_strncmp(game->all_str[i], "WE ", 3) == 0)
// 			{
// 				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
// 				game->we_str = ft_strdup(trim_str);
// 				free(trim_str);
// 			}
// 			else if (ft_strncmp(game->all_str[i], "EA ", 3) == 0)
// 			{
// 				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
// 				game->ea_str = ft_strdup(trim_str);
// 				free(trim_str);
// 			}
// 			else if (ft_strncmp(game->all_str[i], "F ", 2) == 0)
// 			{
// 				game->f_str = ft_strdup(game->all_str[i] + 2);
// 			}
// 			else if (ft_strncmp(game->all_str[i], "C ", 2) == 0)
// 			{
// 				game->c_str = ft_strdup(game->all_str[i] + 2);
// 			}
// 		}
// 		i++;
// 	}
// }

// static void	parse_north_south_texture(t_game *game, size_t *i)
// {
// 	char	*trim_str;

// 	if (ft_strncmp(game->all_str[*i], "NO ", 3) == 0)
// 	{
// 		if (game->no_str)
// 			ft_exit_error("Error\nDuplicate NO identifier.");
// 		trim_str = ft_strtrim(game->all_str[*i] + 3, "\n");
// 		game->no_str = ft_strdup(trim_str);
// 		free(trim_str);
// 	}
// 	else if (ft_strncmp(game->all_str[*i], "SO ", 3) == 0)
// 	{
// 		if (game->so_str)
// 			ft_exit_error("Error\nDuplicate SO identifier.");
// 		trim_str = ft_strtrim(game->all_str[*i] + 3, "\n");
// 		game->so_str = ft_strdup(trim_str);
// 		free(trim_str);
// 	}
// 	(*i)++;
// }

// // 西(WE)と東(EA)のテクスチャパスを処理する関数
// static void	parse_west_east_texture(t_game *game, size_t *i)
// {
// 	char	*trim_str;

// 	if (ft_strncmp(game->all_str[*i], "WE ", 3) == 0)
// 	{
// 		if (game->we_str)
// 			ft_exit_error("Error\nDuplicate WE identifier.");
// 		trim_str = ft_strtrim(game->all_str[*i] + 3, "\n");
// 		game->we_str = ft_strdup(trim_str);
// 		free(trim_str);
// 	}
// 	else if (ft_strncmp(game->all_str[*i], "EA ", 3) == 0)
// 	{
// 		if (game->ea_str)
// 			ft_exit_error("Error\nDuplicate EA identifier.");
// 		trim_str = ft_strtrim(game->all_str[*i] + 3, "\n");
// 		game->ea_str = ft_strdup(trim_str);
// 		free(trim_str);
// 	}
// 	(*i)++;
// }

// // 床(F)と天井(C)の色情報を処理する関数
// static void	parse_floor_ceiling_color(t_game *game, size_t *i)
// {
// 	if (ft_strncmp(game->all_str[*i], "F ", 2) == 0)
// 	{
// 		if (game->f_str)
// 			ft_exit_error("Error\nDuplicate F identifier.");
// 		game->f_str = ft_strdup(game->all_str[*i] + 2);
// 	}
// 	else if (ft_strncmp(game->all_str[*i], "C ", 2) == 0)
// 	{
// 		if (game->c_str)
// 			ft_exit_error("Error\nDuplicate C identifier.");
// 		game->c_str = ft_strdup(game->all_str[*i] + 2);
// 	}
// 	(*i)++;
// }

// // split_line関数を分割したもの
// void	split_line(t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < game->hei)
// 	{
// 		if (game->all_str[i][0])
// 		{
// 			parse_north_south_texture(game, &i);
// 			parse_west_east_texture(game, &i);
// 			parse_floor_ceiling_color(game, &i);
// 		}
// 		else
// 			i++;
// 	}
// }

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
	if (game->all_str[game->hei - 1][0] != '1' && game->all_str[game->hei - 1][0] != ' ' || game->all_str[game->hei - 1][0] == '\0')
		ft_exit_error("Error\nInvalid map");
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
			else if (game->all_str[i][0] == ' ' || game->all_str[i][0] == '1'
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