# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 02:24:32 by stetrel           #+#    #+#              #
#    Updated: 2024/12/14 17:15:46 by stetrel          ###   ########.fr        #
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

SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

RM			:= rm -rf

DIR_UP		= mkdir -p $(@D)

LIBFT_PATH	= ./lib/Libft

MAKEFLAGS   +=	--no-print-directory

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

fclean: clean
	@make fclean -C $(LIBFT_PATH) -s
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

################################################################################

.PHONY: all clean fclean re
