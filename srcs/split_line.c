/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:19 by machi             #+#    #+#             */
/*   Updated: 2024/09/15 15:56:02 by apple            ###   ########.fr       */
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
	int		count;

	i = 0;
	count = 0;
	while (i < game->hei)
	{
		if (game->all_str[i][0])
		{
			if (ft_strncmp(game->all_str[i], "NO ", 3) == 0 && count == 0)
			{
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n"); // 改行文字を削除
				game->no_str = ft_strdup(trim_str);
				count++;
				free(trim_str); // trim_str を解放
			}
			else if (ft_strncmp(game->all_str[i], "SO ", 3) == 0 && count == 1)
			{
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->so_str = ft_strdup(trim_str);
				count++;
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "WE ", 3) == 0 && count == 2)
			{
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->we_str = ft_strdup(trim_str);
				count++;
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "EA ", 3) == 0 && count == 3)
			{
				trim_str = ft_strtrim(game->all_str[i] + 3, "\n");
				game->ea_str = ft_strdup(trim_str);
				count++;
				free(trim_str);
			}
			else if (ft_strncmp(game->all_str[i], "F ", 2) == 0 && count == 4)
			{
				game->f_str = ft_strdup(game->all_str[i] + 2);
				count++;
			}
			else if (ft_strncmp(game->all_str[i], "C ", 2) == 0 && count == 5)
			{
				game->c_str = ft_strdup(game->all_str[i] + 2);
				count++;
			}
			else if (game->all_str[i][0] != '\n' && count >= 0 && count <= 5)
				ft_exit_error("Error\n Failed to read file");
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