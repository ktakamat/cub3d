/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:54 by apple             #+#    #+#             */
/*   Updated: 2024/09/06 19:44:38 by apple            ###   ########.fr       */
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
			return (false);
		i++;
	}
	return (true);
}
