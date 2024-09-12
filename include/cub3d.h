/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:12:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/09/12 20:17:51 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "../libmlx/mlx.h"
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

# define SCREEN_WIDTH 680
# define SCREEN_HEIGHT 480
# define ERROR 1
# define FOV 66

typedef struct s_stack{
	int	x;
	int	y;
}	t_stack;

typedef struct s_mlx{
	void	*m_ptr;
	void	*w_ptr;
}	t_mlx;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;


//プレイヤーがマップのどこにいるのか pos
//プレイヤーの向き
//プレイヤーの視界
typedef struct s_player
{
	int		x;
	int		y;
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line_len;
	int		endian;
	int		wid;
	int		hei;
	int		bits_per_pixel;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;//windows
	t_img		img;
	size_t		hei;
	size_t		wid;
	char		*str_line;
	int 		player_count;
	//新しく追加
	char		**all_str;
	char		*no_str;
	char		*so_str;
	char		*we_str;
	char		*ea_str;
	char		*f_str;
	char		*c_str;
	char		**map_str;
	int			tex_wid;
	int			tex_hei;
	double		height_base; //距離によって壁の高さを変えるための基準
	double		*dist_buffer;
	//playerの設定 pos,dir,plane
	t_player	player;
	t_img		no_tex;
	t_img		so_tex;
	t_img		we_tex;
	t_img		ea_tex;
	uint32_t	ground_color;
	uint32_t	sky_color;
	bool	running;
}	t_game;


typedef struct s_ray
{
	double	camera_x;//-1~1の値。画面のそれぞれの点から、プレイヤーの目線を中心として、左右どちらにどれだけずれているか
	int		map_x;//playerのx座標
	int		map_y;//playerのy座標
	t_vec2	dir; //光線ベクトル
	double	side_dist_x;//今いる位置から横方の壁の距離
	double	side_dist_y;//今いる位置から縦方向の壁の距離
	double	perp_wall_dist; //このメンバーは、カメラの方向に対して壁までの距離を表す
	int		side;
	int		step_x;
	int		step_y;
	double	delta_dist_x;//画面に映る壁との距離
	double	delta_dist_y;//
	t_img	*tex;
}	t_ray;

typedef struct s_ray_data
{
	double		camera_x;
	t_player	player;
	t_vec2		dir;
	t_vec2		side_dist;
	t_vec2		delta_dist;
	t_vec2		step;
	t_vec2		map;
	int			side;
}	t_ray_data;

typedef struct s_wall
{
	int		line_hei;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		texture_x;
	double	step;
	double	texture_pos_y;
	int		texture_y;
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

//math.c
double	change_pi(double x);
size_t	c_str_count(char *str, char c);
double	vec_len(t_vec2 vec);

//map.c
void	map_read(char *filename, t_game *game);

// init_set.c
void	init_game(t_game *game);
void	set_player(t_game *game);
void	set_game_tex(t_game *game);

//utli.c
void	ft_exit_error(const char *str);
int		split_size(char *str, char c);
bool	str_all_num(char *str);
uint32_t	get_color(t_img img, int x, int y);

//map_read.c
void	get_map_size(char *filename, t_game *game);
void	map_load(char *filename, t_game *game);

//map_error.c
void	map_word_check(t_game *game);

//map_color.c
int	set_color(t_game *game);

//split_line.c
void	split_line(t_game *game);
void	store_map(t_game *game);

//debug.c
void	print_map(t_game *game);
void    print_map_str(t_game *game);
void	print_game(t_game *game);
void	print_rgb(char **rgb);
void	libmlx(t_game *game);
void	print_texture(t_game *game);

//map_check.c
void	surround_wall(t_game *game);

//ptrarr_utlis.c
void	ptrarr_free(void **ptrarr);

//create_window.c
int	create_window(t_game *game);

//create_wall.c
void	create_wall(t_game *game);

//set_color.c
uint32_t	get_color_f(t_game *game, uint32_t *color);
uint32_t	get_color_c(t_game *game, uint32_t *color);
bool	color_set_check(t_game *game);

//ptrarr_utlis.c
void	ptrarr_free(void **ptrarr);

#endif