NAME := Cub3D

CFLAGS = -Wextra -Wall -Werror

HEADERS := -I ./include

SRCDIR := ./src/
SRCS := $(SRCDIR)main.c

OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC := cc

.PHONY: all clean fclean re

all: $(NAME)

libft:
	@make -C libft

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) libft
	$(CC) $(OBJS) -o $(NAME) $(HEADERS)

clean:
	@make -C libft clean
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm
