# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2025/11/30 13:32:36 by takaito             #+#    #+#             #
#   Updated: 2025/11/30 13:32:36 by takaito            ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = AR
ARFLAGS = rcs
DEBUGFLAGS = -DDEBUG=1

# Path and library
DIR = $(shell pwd)
OS = $(shell uname)
LIB_DIR = $(DIR)/lib/
LIBFT_DIR = $(LIB_DIR)/libft/
LIBFT = $(LIBFT_DIR)libft.a
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
	MLX_DIR = $(LIB_DIR)/minilibx-opengl
endif
ifeq ($(UNAME),Linux)
	MLX_DIR = $(LIB_DIR)/minilibx-linux
	MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz
endif
MLX = $(MLX_DIR)/libmlx.a
LIBFLAGS = -L$(LIBFT_DIR) -lft
OBJ_DIR = $(DIR)/objs/
SRC_DIR = $(DIR)/srcs/
HEADER_DIR = $(DIR)/includes/
HEADER = $(HEADER_DIR)cub3d.h
SRCS = \
	main.c player.c event.c texture.c \
	render.c render_utils.c \
	init_ray.c init_wall.c \
	init_game.c init_map.c init_map_utils.c \
	init_player.c parse_colour.c \
	parse_map.c parse_wall.c parse_wall_utils.c \
	put_error.c validate_argv.c file_utils.c \
	free_game.c free_map.c cleanup.c\
	validate_map.c validate_map_utils.c \
	game_loop.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)


INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re
