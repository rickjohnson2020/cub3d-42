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

NAME = cub3d

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = AR
ARFLAGS = rcs
DEBUGFLAGS = -DDEBUG=1 

# Path and library
DIR = $(shell pwd)
LIB_DIR = $(DIR)/lib/
LIBFT_DIR = $(LIB_DIR)/libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = $(LIB_DIR)/mlx/ # it could be changed 
LIBFLAGS = -L$(LIBFT_DIR) -lft
OBJ_DIR = $(DIR)/objs/
SRC_DIR = $(DIR)/srcs/
HEADER_DIR = $(DIR)/includes/
HEADER = $(HEADER_DIR)cub3d.h
STUB_SRC = #$(SRC_DIR)debug_stub.c
DEBUG_SRC = #$(SRC_DIR)debug_utils.c
SRC = \
	$(SRC_DIR)main.c \
	$(SRC_DIR)validate_argv.c \
	$(SRC_DIR)file_utils.c \
	$(SRC_DIR)put_error.c \
	$(SRC_DIR)init_game.c \
	$(SRC_DIR)init_map.c \
	$(SRC_DIR)free_game.c \
	$(SRC_DIR)free_map.c \
	$(SRC_DIR)parse_wall.c \
	$(SRC_DIR)parse_floor_and_ceiling.c \
	$(SRC_DIR)parse_map.c \

OBJ = \
	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) \
	$(STUB_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DEBUG = \
	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) \
	$(DEBUG_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

print:
	@echo $(OBJ)
	@echo "\n"
	@echo $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

debug: $(OBJ_DEBUG)
	$(CC) $(CFLAGS) $(OBJ_DEBUG) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug print
