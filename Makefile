# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 18:46:55 by aghergut          #+#    #+#              #
#    Updated: 2025/02/07 11:51:05 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DARK_GREEN = \033[38;5;22m
GRAY = \033[0;90m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET_COLOR = \033[0m

NAME = push_swap

COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/
MAKE_LIBFT = @make -C $(LIBFT)
FCLEAN_LIBFT = @make fclean -C $(LIBFT)
FLAGS_LIBFT = -Llibft -lft
INCLUDES = -Ilibft -I.

INSTR_FOLDER = instructions/
MAIN_FOLDER = ./

SRCS_INSTR = 	$(INSTR_FOLDER)push_case.c \
				$(INSTR_FOLDER)rotate_case.c \
				$(INSTR_FOLDER)rrotate_case.c \
				$(INSTR_FOLDER)swap_case.c
SRCS_MAIN = 	$(MAIN_FOLDER)check_av.c \
				$(MAIN_FOLDER)push_swap.c

OBJS_INSTR = $(INSTR_FOLDER)o_files/
OBJS_MAIN = $(MAIN_FOLDER)o_files/

OBJS = 	$(SRCS_INSTR:$(INSTR_FOLDER)%.c=$(OBJS_INSTR)%.o) \
		$(SRCS_MAIN:$(MAIN_FOLDER)%.c=$(OBJS_MAIN)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Trying to make push_swap program..."
	@echo "$(GRAY)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS) $(FLAGS_LIBFT) -o $(NAME)
	@echo "$(DARK_GREEN)Program compiled successfully!$(RESET_COLOR)"

$(OBJS_INSTR)%.o: $(INSTR_FOLDER)%.c
	@mkdir -p $(OBJS_INSTR)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_MAIN)%.o: $(MAIN_FOLDER)%.c
	@mkdir -p $(OBJS_MAIN)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -Rf $(OBJS_INSTR)
	@rm -Rf $(OBJS_MAIN)
	@make clean -s -C libft > /dev/null 2>&1
	@echo "push_swap successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@$(FCLEAN_LIBFT)

re: fclean all

.PHONY: all clean fclean re
