# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 18:46:55 by aghergut          #+#    #+#              #
#    Updated: 2025/02/24 15:28:10 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

# COLORS
DARK_GREEN = \033[38;5;22m
GRAY = \033[0;90m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET_COLOR = \033[0m

# PROGRAM NAME
NAME = push_swap

# COMPILER AND FLAGS
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

# LIBFT COMMANDS
LIBFT = libft/
MAKE_LIBFT = @make -C $(LIBFT)
FCLEAN_LIBFT = @make fclean -C $(LIBFT)
FLAGS_LIBFT = -Llibft -lft

# INCLUDES
INCLUDES = -Ilibft -I.

# SOURCES
SRCS = 	instructions/push_case.c \
		instructions/rotate_case.c \
		instructions/rrotate_case.c \
		instructions/swap_case.c \
		check_av.c \
		sort_min.c \
		sort_large.c \
		sort_utils.c \
		push_swap.c

# OBJECTS
OBJS_FOLDER = objects/
OBJS = 	$(SRCS:%.c=$(OBJS_FOLDER)%.o)

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Trying to make push_swap program..."
	@echo "$(GRAY)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS) $(FLAGS_LIBFT) -o $(NAME)
	@echo "$(DARK_GREEN)Program compiled successfully!$(RESET_COLOR)"

$(OBJS_FOLDER)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -Rf $(OBJS_FOLDER)
	@make clean -s -C libft > /dev/null 2>&1
	@echo "push_swap successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@$(FCLEAN_LIBFT)

re: fclean all

.PHONY: all clean fclean re
