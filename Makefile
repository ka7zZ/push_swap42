# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 18:46:55 by aghergut          #+#    #+#              #
#    Updated: 2025/02/28 08:11:54 by aghergut         ###   ########.fr        #
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
CHECKER = checker

# COMPILER AND FLAGS
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

# LIBFT COMMANDS
LIBFT = libft/
MAKE_LIBFT = @make -C $(LIBFT)
FCLEAN_LIBFT = @make fclean -C $(LIBFT)
FLAGS_LIBFT = -Llibft -lft

# INCLUDES
INCLUDES_NORMAL = -Ilibft -Iinclude/
INCLUDES_CHECKER = -Ilibft -Iinclude/

# SOURCES
SRCS_MANDATORY = 	srcs/mandatory/instructions/push_case.c \
					srcs/mandatory/instructions/rotate_case.c \
					srcs/mandatory/instructions/rrotate_case.c \
					srcs/mandatory/instructions/swap_case.c \
					srcs/mandatory/check_args/check_args.c \
					srcs/mandatory/sort/sort_min.c \
					srcs/mandatory/sort/sort_large.c \
					srcs/mandatory/sort/sort_utils.c \
					srcs/mandatory/push_swap.c

SRCS_CHECKER =	srcs/bonus/instructions/push_checker.c \
				srcs/bonus/instructions/rotate_checker.c \
				srcs/bonus/instructions/rrotate_checker.c \
				srcs/bonus/instructions/swap_checker.c \
				srcs/bonus/create_list.c \
				srcs/bonus/checker.c

# OBJECTS
OBJS_PUSH = objects_pushswap/
OBJS_CHECK = objects_checker/
OBJS_MAND = $(SRCS_MANDATORY:%.c=$(OBJS_PUSH)%.o)
OBJS_CHECKER = $(SRCS_CHECKER:%.c=$(OBJS_CHECK)%.o)

# RULES
all: $(NAME)

$(NAME): $(OBJS_MAND)
	@echo "Trying to make push_swap program..."
	@echo "$(GRAY)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS_MAND) $(FLAGS_LIBFT) -o $(NAME)
	@echo "$(DARK_GREEN)Program compiled successfully!$(RESET_COLOR)"

$(OBJS_PUSH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_NORMAL) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJS_CHECKER)
	@echo "$(CYAN)Creating el checker$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS_CHECKER) $(FLAGS_LIBFT) -o $(CHECKER)
	@echo "$(DARK_GREEN)Program compiled successfully!$(RESET_COLOR)"

$(OBJS_CHECK)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_CHECKER) -c $< -o $@
	
clean:
	@rm -Rf $(OBJS_PUSH) $(OBJS_CHECK)
	@make clean -s -C libft > /dev/null 2>&1
	@echo "push_swap successfully cleaned!"

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@$(FCLEAN_LIBFT)

re: fclean all

.PHONY: all clean fclean re
