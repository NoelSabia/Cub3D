NAME := Cub3D

CFLAGS = -Wextra -Wall #-Werror

HEADERS := -I ./include -I ./libft -I ./MLX/include

SRCDIR := ./src/
SRCS := $(SRCDIR)main.c \
		$(SRCDIR)init.c \
        $(SRCDIR)parsing/parsing.c \
		$(SRCDIR)parsing/parsing_fill_struct.c \
		$(SRCDIR)parsing/parsing_flood_fill_helper.c \
		$(SRCDIR)parsing/parsing_flood_fill_preparation.c \
		$(SRCDIR)parsing/parsing_flood_fill.c \
		$(SRCDIR)player_movement/player_movement.c \
		$(SRCDIR)raycasting/raycasting.c \
		$(SRCDIR)walls/floor_ceiling_color.c

OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC := gcc -fsanitize=address -g


MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

.PHONY: all clean fclean re

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(MLX):
	@cd $(MLX_DIR)/build && cmake .. && make -j4

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS) libft/libft.a $(MLX)
	$(CC) $(OBJS) -o $(NAME) -Llibft -lft $(MLX_FLAGS)

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MLX_DIR)/build clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME)
	@rm -rf $(MLX)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm