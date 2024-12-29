# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 04:41:18 by stetrel           #+#    #+#              #
#    Updated: 2024/12/29 11:35:51 by swenn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include pimp_makefile.mk

NAME		:= pipex

NAME_BONUS	:= pipex_bonus

SRCS_DIR	:= src

OBJS_DIR	:= .objs

BONUS_DIR	:= bonus

CC			:= cc

CFLAGS		:= -Wall -Wextra -Werror -g

IFLAGS		:= -I ./includes

SRCS		:= main.c \
			   error.c \
			   parsing/pipex_parsing.c \
			   process/process.c \

SRCS_BONUS	:= bonus/main_bonus.c \
			   bonus/pipex_bonus_parsing.c \
			   error.c \
			   bonus/utils_bonus.c \
			   bonus/exec_bonus.c \
			   process/process.c \
			   parsing/pipex_parsing.c \

SRCS_BONUS	:= $(addprefix $(SRCS_DIR)/, $(SRCS_BONUS))

SRCS	:= $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

OBJS_BONUS	:= $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:%.c=%.o))

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
	@$(RM) $(OBJS_BONUS)
	@make clean -C $(LIBFT_PATH) -s
	@echo "$(RED)objs removed$(RESET)"
	@echo "$(RED)objs bonus removed$(RESET)"
	@echo "$(RED)Libft objs removed$(RESET)"

fclean: clean
	@echo "$(RED)$(NAME) removed"
	@echo "$(RED)$(NAME_BONUS) removed"
	@make fclean -C $(LIBFT_PATH) -s
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)


re:
	@$(MAKE) fclean
	@$(MAKE) all

################################################################################

RED			= \033[31;49m

YELLOW		= \033[0;33m

GREEN		= \033[0;32m

RESET		= \033[0m

################################################################################

.PHONY: all clean fclean re
