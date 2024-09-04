/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:12:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/09/04 17:18:49 by machi            ###   ########.fr       */
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
# include "../libft/ft_get_next_line/get_next_line.h"
# include "../libft/ft_printf.h"
// # include "../minilibx-linux/mlx.h"
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
	size_t	hei_map;
	size_t	wid;
	void	*mx;
	void	*win;
	char	*str_line;
	//新しく追加
	char	**all_str;
	char	*no_str;
	char	*so_str;
	char	*we_str;
	char	*ea_str;
	char	*f_str;
	char	*c_str;
	char	**map_str;
	char	col_cnt;
	char	all_col;
	int		walk_cnt;
	int		flag;
	int		top;
	int		now_col;
	int		xi;
	int		yi;
	int		error_item;
	int		player_count;
	t_stack	*player;
	bool	running;
}	t_game;

typedef struct s_ray
{
	double	camera_x;
	
	int		map_x;
	int		map_y;
	

	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist; //このメンバーは、カメラの方向に対して壁までの距離を表す
	int		side;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	t_img	*img;
}	t_ray;

typedef struct s_wall
{
	
}	t_wall;

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

//map.c
void	map_read(char *filename, t_game *game);

//utli.c
void	ft_exit_error(const char *str);

//map_read.c
void	init_game(t_game *game);
void	get_map_size(char *filename, t_game *game);
void	map_load(char *filename, t_game *game);
void	get_map_size(char *filename, t_game *game);

//map_error.c
void	map_word_check(t_game *game);

//split_line.c
void	split_line(t_game *game);
void	store_map(t_game *game);


//debug.c
void	print_map(t_game *game);
void    print_map_str(t_game *game);

//map_check.c
void	surround_wall(t_game *game);

#endif