# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riyano <riyano@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 18:51:08 by riyano            #+#    #+#              #
#    Updated: 2025/11/30 18:51:15 by riyano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_DIR = srcs
BUILD_DIR = build

SRC_FILES = main.c init.c render.c player.c event.c texture.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -g

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

#MLX_DIR = ./minilibx-linux
MLX_DIR = ./minilibx-opengl
MLX = $(MLX_DIR)/libmlx.a
#MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c includes/cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re
