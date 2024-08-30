NAME = cub3D
SRCS = srcs/main.c srcs/map.c srcs/utlis.c\
	srcs/map_read.c \
	srcs/debug.c \
	libft/ft_get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o)
CC = gcc
LIBS = -Llib -lft -lmlx -framework OpenGL -framework AppKit

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a


$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

all: $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
