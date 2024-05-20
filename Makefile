NAME	:= Cub3D

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -I ./include

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c

OBJDIR := ./obj/
OBJS	:= $(SRCS:.c=.o)
OBJS	:= $(addprefix $(OBJDIR),$(OBJS))

CC		:= cc

.PHONY: all, clean, fclean, re

all: $(NAME)

libft:
	@make -C ./lib/libft

get_next_line:
	@make -C ./lib/get_next_line

$(OBJDIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) libft get_next_line
	$(CC) $(OBJS) ./lib/libft/libft.a ./lib/get_next_line/get_next_line.a $(HEADERS) -lreadline -lncurses -ltermcap -o $(NAME)

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/get_next_line clean
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/get_next_line fclean
	@rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm
