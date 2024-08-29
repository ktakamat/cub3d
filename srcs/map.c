/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:41:31 by ktakamat          #+#    #+#             */
/*   Updated: 2024/08/29 18:54:42 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin_new(char *s1, const char *s2)
{
	char	*a;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)ft_calloc(sizeof(*a), (len_s1 + len_s2) + 1);
	if (a == NULL)
		ft_exit();
	ft_strlcpy(a, s1, len_s1 + 1);
	ft_strlcat(a, s2, len_s1 + len_s2 + 1);
	if (a[len_s1 + len_s2 - 1] == '\n')
		a[len_s1 + len_s2 - 1] = '\0';
	free(s1);
	s1 = NULL;
	return (a);
}

void	map_word(char *map_str)
{
	if (!map_str)
		return ;
	while (*map_str && map_str)
	{
		if (*map_str == '\n')
			return ;
		if (*map_str != '1' && *map_str != 'N'
			&& *map_str != 'S' && *map_str != 'E'
			&& *map_str != 'W' && *map_str != ' ' && *map_str != '\n')
			ft_exit();
		map_str++;
	}
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	game->error_item = 0;
	line = get_next_line(fd);
	if (line == NULL || *line == '\0' || *line == '\n')
		ft_exit();
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	game->hei = 0;
	game->wid = 0;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		map_word(line);
		if (line)
			game->str_line = ft_strjoin_new(game->str_line, line);
		free(line);
	}
	close(fd);
}
