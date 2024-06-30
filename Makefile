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
		$(SRCDIR)raycasting/raycasting.c  \
		$(SRCDIR)parsing/parsing_helper4.c

OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

MLX_LIB		= ./MLX42/build/libmlx42.a
MLX_PATH	= ./MLX42
MLX			= -ldl -lglfw -pthread -lm

CC := cc


MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

.PHONY: all clean fclean re

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(OBJDIR)%.o: $(SRCDIR)%.c $(MLX_LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(MLX_PATH)/include -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) $(MLX_LIB) $(MLX) -o $(NAME) -Llibft -lft -lm

$(MLX_LIB):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX_PATH)
	mkdir -p $(MLX_PATH)/build
	cd $(MLX_PATH)/build && cmake ..
	make -C $(MLX_PATH)/build

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MLX_DIR)/build clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C libft fclean
	rm -rf $(MLX_PATH)
	@rm -rf $(NAME)
	@rm -rf $(MLX)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm
