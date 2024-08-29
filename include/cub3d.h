/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:12:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/08/29 17:26:58 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_stack{
	int	x;
	int	y;
}	t_stack;

typedef struct s_mlx{
	void	*m_ptr;
	void	*w_ptr;
}	t_mlx;

typedef struct s_img{
	void	*land;
	void	*wall;
	void	*chara;
	void	*chest;
	void	*chest_open;
	void	*rune;
	void	*runl;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	t_mlx	mlx;
	t_img	img;
	size_t	hei;
	size_t	wid;
	void	*mx;
	void	*win;
	char	*str_line;
	char	col_cnt;
	char	all_col;
	int		walk_cnt;
	int		flag;
	int		top;
	int		now_col;
	int		xi;
	int		yi;
	int		error_item;
	bool	running;
}	t_game;

typedef struct s_ma
{
	void		*mlx;
	void		*win;
}	t_ma;

typedef struct s_last
{
	size_t	index;
	size_t	expected_width;
	size_t	last_width;
	size_t	i;
	char	*last_line_start;
	char	*last_line_end;
	char	*ptr;
}	t_last;

#endif