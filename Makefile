# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 15:59:32 by yorlians          #+#    #+#              #
#    Updated: 2023/04/29 20:12:19 by yorlians         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CFLAGS := -Wextra -Wall -Werror
LIBMLX_FOLDER := lib/MLX42
LIBMLX := $(LIBMLX_FOLDER)/build/libmlx42.a
LIBFT_FOLDER := lib/libft
LIBFT := $(LIBFT_FOLDER)/libft.a

HEADERS := -I include -I $(LIBMLX_FOLDER)/include
LIBS := $(LIBMLX) $(LIBFT) -ldl -L"/Users/yorlians/.brew/Cellar/glfw/3.3.8/lib/" -lglfw -pthread -lm
SRCS_BONUS :=	s_l_b/check_map_bonus.c s_l_b/check_map_utils_bonus.c s_l_b/dfs_bonus.c \
				s_l_b/draw_map_bonus.c s_l_b/draw_map_utils_bonus.c s_l_b/free_all_bonus.c \
				s_l_b/hooks_bonus.c s_l_b/init_game_bonus.c s_l_b/init_map_bonus.c s_l_b/move_player_bonus.c \
				s_l_b/so_long_bonus.c s_l_b/utils_bonus.c
SRCS := src/check_map_utils.c src/check_map.c src/dfs.c src/draw_map_utils.c src/draw_map.c \
		src/free_all.c src/hooks.c src/init_game.c src/init_map.c src/move_player.c \
		src/so_long.c src/utils.c
OBJS := ${SRCS:.c=.o}
OBJS_BONUS := ${SRCS_BONUS:.c=.o}

all: $(LIBMLX) $(LIBFT) $(NAME)

$(LIBMLX):
	@cmake $(LIBMLX_FOLDER) -B $(LIBMLX_FOLDER)/build && make -C $(LIBMLX_FOLDER)/build -j4

$(LIBFT):
	@make all -C $(LIBFT_FOLDER)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: $(LIBMLX) $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME)
	
clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make clean -C $(LIBFT_FOLDER)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX_FOLDER)/build
	@make fclean -C $(LIBFT_FOLDER)

re: clean all

.PHONY: all, clean, fclean, re