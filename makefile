# Makefile
NAME = cub3D
SRCS = srcs/main.c \
	srcs/utlis.c \
	srcs/map_load.c \
	srcs/debug.c \
	srcs/map_check.c \
	srcs/map_error.c \
	srcs/split_line.c \
	srcs/math.c \
	srcs/init_set.c \
	srcs/create_window.c \
	srcs/map_color.c \
	srcs/ptrarr_utlis.c \
	srcs/create_wall.c \
	srcs/re_set_player.c \
	srcs/mlx_hook.c \
	srcs/error.c \
	libft/ft_get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o)
CC = gcc

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

MLXDIR = ./libmlx
MLX = $(MLXDIR)/libmlx.a

# IDFLAGS
IDFLAGS = -I./libft -I./libft/ft_get_next_line -I./libft/ft_printf -I./includes -I$(MLXDIR) -I/usr/X11/include

# LDFLAGS
LDFLAGS = -L./libft -L$(MLXDIR) -L/usr/X11/lib -lm -lX11 -lXext

LIBS = -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(LDFLAGS) $(IDFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(LIBFT):
	make -C $(LIBDIR)

$(MLX):
	make -C $(MLXDIR)

%.o: %.c
	$(CC) $(IDFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
