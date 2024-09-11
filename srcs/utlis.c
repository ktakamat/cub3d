/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:54 by apple             #+#    #+#             */
/*   Updated: 2024/09/10 20:33:27 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_exit_error(const char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	split_size(char *str, char c)
{
	int		split_size;

	split_size = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (!*str)
			break;
		while (*str && *str != c)
			str++;
		split_size++;
	}
	return (split_size);
}

bool	str_all_num(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

uint32_t	get_color(t_img img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
