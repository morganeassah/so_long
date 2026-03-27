
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXDIR = minilibx
MLX = -L$(MLXDIR) -lmlx -lXext -lX11 -lm
LIBFTDIR = libft

SRCS = so_long.c \
	check_map.c \
	check_map_utils.c \
	check_map_utils2.c \
	put_map_to_window.c \

OBJS = $(SRCS:.c=.o)

INLCUDES = -I$(MLXDIR) -I$(LIBFTDIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L$(LIBFTDIR) -lft $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(MLXDIR) fclean

re: fclean all

.PHONY: all clean fclean re
