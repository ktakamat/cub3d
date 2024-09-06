/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrarr_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:46:21 by apple             #+#    #+#             */
/*   Updated: 2024/09/06 21:48:24 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ptrarr_free(void **ptrarr)
{
	size_t	i;

	i = 0;
	while (ptrarr[i])
	{
		free(ptrarr[i])
		ptrarr[i] = NULL;
		i++;
	}
	free(ptrarr);
}
