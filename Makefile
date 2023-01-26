# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:45:23 by laugarci          #+#    #+#              #
#    Updated: 2023/01/26 11:57:00 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.a
HEADER	= so_long.h

CFLAGS	= -Wall -Wextra -Werror

MLXCC	= -I mlx -L ./mlx -lmlx
OPENGL	= -framework OpenGL -framework AppKit

INC		= -I ./mlx -I ./

CC		= gcc

NORM	= norminette -R CheckForbiddenSourceHeader

RM		= rm -f

AR		= ar -rcs

SRC_FILES	= so_long.c \
			  so_long_utils.c \
			  check_limits.c \
			  check_path.c \

SRC_OBJ		= $(SRC_FILES:.c=.o)

SRC_DEPS	= $(SRC_FILES:.c=.d)

$(MLX): @make -s -C mlx

all: $(MLX) $(NAME) 

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compiling $<..."	

$(NAME) : $(SRC_OBJ)
	@$(CC) $(SRC_OBJ) $(MLXCC) $(OPENGL) -o $(NAME)
	@echo Compiled!

clean:
	@$(RM) $(SRC_OBJ) $(SRC_DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	$(NORM)

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm
