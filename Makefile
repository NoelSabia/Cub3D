NAME := Cub3D

CFLAGS = -Wextra -Wall 

HEADERS := -I ./include -I ./libft -I ./MLX/include

SRCDIR := ./src/
SRCS := $(SRCDIR)main.c \
		$(SRCDIR)init.c \
        $(SRCDIR)parsing/parsing.c \
		$(SRCDIR)parsing/parsing_helper.c \
		$(SRCDIR)parsing/parsing_helper2.c \
		$(SRCDIR)parsing/parsing_helper3.c \
		$(SRCDIR)raycasting/raycasting.c

OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC := cc


MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

.PHONY: all clean fclean re

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(MLX):
	cd $(MLX_DIR)/build && cmake .. && make -j4

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
