# Makefile
NAME = cub3D
SRCS = srcs/main.c \
	srcs/utlis.c \
	srcs/map_read.c \
	srcs/debug.c \
	srcs/map_check.c \
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
