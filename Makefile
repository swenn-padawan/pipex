# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 02:24:32 by stetrel           #+#    #+#              #
#    Updated: 2024/12/22 23:51:17 by jlorette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include pimp_makefile.mk

NAME		:= pipex

SRCS_DIR	:= src

OBJS_DIR	:= .objs

CC			:= cc

CFLAGS		:= -Wall -Wextra -Werror -g

IFLAGS		:= -I ./includes

SRCS		:= main.c \
			   error.c \
			   parsing/pipex_parsing.c \
			   process/process.c \

SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

RM			:= rm -rf

DIR_UP		= mkdir -p $(@D)

LIBFT_PATH	= ./lib/Libft

MAKEFLAGS	+= --no-print-directory

################################################################################

all: $(NAME)

$(NAME):	$(LIBFT_PATH)/libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT_PATH)/libft.a $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PATH)/libft.a -o $(NAME_BONUS)

$(OBJS_DIR)/%.o:%.c
	@$(DIR_UP)
	@$(call run_and_test, $(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<)

$(LIBFT_PATH)/libft.a:
	@make -C $(LIBFT_PATH) -s

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH) -s
	@echo "$(RED)objs removed$(RESET)"
	@echo "$(RED)Libft objs removed$(RESET)"

fclean: clean
	@echo "$(RED)$(NAME) removed"
	@make fclean -C $(LIBFT_PATH) -s
	@$(RM) $(NAME)


re:
	@$(MAKE) fclean
	@$(MAKE) all

################################################################################

RED			= \033[31;49;1m

YELLOW		= \033[0;33m

GREEN		= \033[0;32m

RESET		= \033[0m

################################################################################

.PHONY: all clean fclean re
