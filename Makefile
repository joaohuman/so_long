# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 00:20:42 by jvictor-          #+#    #+#              #
#    Updated: 2022/01/20 01:03:16 by jvictor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = main.c \
			get_next_line.c \
			get_next_line_utils.c \
			check_args.c \
			open_map.c \
			init_struct.c \
			free_mallocs.c \
			check_map.c \
			remove_barn.c \
			free_exit.c
			
SRC_DIR = ./source
MLX_DIR = ./minilibx-linux/
MLX = ./minilibx-linux/libmlx.a
CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address
CC = clang
LIBS_FLAGS = -lmlx -Ilmlx -lXext -lX11
OBJECT = $(addprefix $(OBJECT_DIR)/,$(subst .c,.o,$(SRC_FILES)))
OBJECT_DIR = ./objects
LIBFT = libft/libft.a
LIBFT_DIR = ./libft
INCLUDES = ./includes
MAKE_DIR = mkdir -p
NAME = so_long

all:	$(NAME)

$(NAME):	$(MLX) $(OBJECT) $(LIBFT)
		$(CC) $(CFLAGS) -g $(OBJECT) -L $(MLX_DIR) $(LIBFT) $(LIBS_FLAGS) $(MLX) -o $(NAME)

$(OBJECT_DIR)/%.o:	$(SRC_DIR)/%.c
		$(MAKE_DIR) $(OBJECT_DIR)
		$(CC) $(CFLAGS) -g -I $(INCLUDES) -o $@ -c $<

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX):
		$(MAKE) -C $(MLX_DIR)

clean:
		rm -fr $(OBJECT_DIR)
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re