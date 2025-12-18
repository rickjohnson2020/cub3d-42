# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takaito <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 08:33:14 by takaito           #+#    #+#              #
#    Updated: 2025/06/18 12:52:21 by takaito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compiler and flags
CC = gcc
CFLAG = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

# Path
DIR = $(shell pwd)
DIR_PRINTF = $(DIR)/ft_printf
DIR_GNL = $(DIR)/get_next_line
OBJ_DIR = $(DIR)/objs
SRCS = \
	$(DIR)/ft_atoi.c \
	$(DIR)/ft_bzero.c \
	$(DIR)/ft_calloc.c \
	$(DIR)/ft_isalnum.c \
	$(DIR)/ft_isalpha.c \
	$(DIR)/ft_isascii.c \
	$(DIR)/ft_isdigit.c \
	$(DIR)/ft_isprint.c \
	$(DIR)/ft_memchr.c \
	$(DIR)/ft_memcmp.c \
	$(DIR)/ft_memcpy.c \
	$(DIR)/ft_memmove.c \
	$(DIR)/ft_memset.c \
	$(DIR)/ft_strchr.c \
	$(DIR)/ft_strdup.c \
	$(DIR)/ft_strlcat.c \
	$(DIR)/ft_strlcpy.c \
	$(DIR)/ft_strlen.c \
	$(DIR)/ft_strncmp.c \
	$(DIR)/ft_strnstr.c \
	$(DIR)/ft_strrchr.c \
	$(DIR)/ft_tolower.c \
	$(DIR)/ft_toupper.c \
	$(DIR)/ft_substr.c \
	$(DIR)/ft_strjoin.c \
	$(DIR)/ft_strtrim.c \
	$(DIR)/ft_split.c \
	$(DIR)/ft_itoa.c \
	$(DIR)/ft_strmapi.c \
	$(DIR)/ft_striteri.c \
	$(DIR)/ft_putchar_fd.c \
	$(DIR)/ft_putstr_fd.c \
	$(DIR)/ft_putendl_fd.c \
	$(DIR)/ft_putnbr_fd.c \
	$(DIR_PRINTF)/ft_printf.c \
	$(DIR_PRINTF)/ft_convert_to_hex.c \
	$(DIR_PRINTF)/ft_convert_to_hex_int.c \
	$(DIR_PRINTF)/ft_print_char.c \
	$(DIR_PRINTF)/ft_print_hex.c \
	$(DIR_PRINTF)/ft_print_int.c \
	$(DIR_PRINTF)/ft_print_ptr.c \
	$(DIR_PRINTF)/ft_print_str.c \
	$(DIR_PRINTF)/ft_print_u_int.c \
	$(DIR_PRINTF)/ft_put_u_int_fd.c \
	$(DIR_PRINTF)/ft_print_null_ptr.c \
	$(DIR_GNL)/get_next_line.c \
	
# Bonus
BONUS_SRCS = \
	$(DIR)/ft_lstnew.c \
	$(DIR)/ft_lstsize.c \
	$(DIR)/ft_lstmap.c \
	$(DIR)/ft_lstlast.c \
	$(DIR)/ft_lstiter.c \
	$(DIR)/ft_lstdelone.c \
	$(DIR)/ft_lstclear.c \
	$(DIR)/ft_lstadd_front.c \
	$(DIR)/ft_lstadd_back.c \

BONUS_OBJS = $(BONUS_SRCS:$(DIR)/%.c=$(OBJ_DIR)/%.o)

OBJS = $(SRCS:$(DIR)/%.c=$(OBJ_DIR)/%.o) 
TARGET = $(DIR)/$(NAME)
HEADER = $(DIR)/libft.h

# Default target
$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY: all clean fclean re bonus
