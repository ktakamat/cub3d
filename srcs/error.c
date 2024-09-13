/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:13:23 by apple             #+#    #+#             */
/*   Updated: 2024/09/13 17:13:40 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	have_ber(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext != NULL && ft_strcmp(ext, FILE_EXTENSION) == 0)
		return (true);
	return (false);
}

