# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:19:02 by laugarci          #+#    #+#              #
#    Updated: 2023/05/31 17:37:36 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILES = check_limits.c \
		 check_path.c \
		 ft_finish.c \
		 ft_movements.c \
		 ft_put_images.c \
		 ft_window.c \
		 so_long.c \
		 so_long_utils.c \
		 get_next_line/get_next_line.c \
		 get_next_line/get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o)
DEPS	= $(CFILES:.c=.d)

all: subsystems $(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD -Imlx -c $< -o $@
	@echo "Compiling $<..."

subsystems:
	make -C $(MLX_PATH) all

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_LIB) $(OBJECTS) -o $(NAME)

clean:
	@$(RM) $(OBJECTS) $(DEPS)
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	norminette check_limits.c check_path.c ft_movements.c ft_put_images.c ft_window.c get_next_line so_long.c so_long_utils.c so_long.h

.PHONY: all clean fclean re norm
