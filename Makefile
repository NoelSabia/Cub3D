NAME := Cub3D

CFLAGS = -Wextra -Wall -Werror

HEADERS := -I ./include -I ./libft

SRCDIR := ./src/
SRCS := $(SRCDIR)main.c \
        $(SRCDIR)parsing/parsing.c \
		$(SRCDIR)parsing/parsing_helper.c

OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC := cc

.PHONY: all clean fclean re

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) -o $(NAME) -Llibft -lft -lm

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm
