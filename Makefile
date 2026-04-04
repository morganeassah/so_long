
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXDIR = minilibx
MLX = -L$(MLXDIR) -lmlx -lXext -lX11 -lm
LIBFTDIR = libft
OBJDIR = obj

SRCS = main.c \
	hooks.c \
	free.c \
	flood_fill.c \
	check_map.c \
	forme_map.c \
	forme_map_utils.c \
	check_items.c \
	put_map_to_window.c \
	mouvements.c \
	mouvements_utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INLCUDES = -I$(MLXDIR) -I$(LIBFTDIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L$(LIBFTDIR) -lft $(MLX) -o $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(MLXDIR) fclean

re: fclean all

.PHONY: all clean fclean re
