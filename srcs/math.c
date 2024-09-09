/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:05:52 by apple             #+#    #+#             */
/*   Updated: 2024/09/08 18:25:32 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	change_pi(double x)
{
	return ((double)x / 180 * M_PI);
}

size_t	c_str_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

double	vec_len(t_vec2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}