# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:45:23 by laugarci          #+#    #+#              #
#    Updated: 2023/01/13 20:48:37 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.a
MLX		= mlx/Makefile.gen
HEADER	= so_long.h
INCLUDE	= -I ./mlx
CFLAGS	= -Wall -Wextra -Werror -Imlx
CC		= gcc
NORM	= norminette -R CheckForbiddenSourceHeader
OPENGL	= -framework OpenGL -framework AppKit
RM		= rm -f
AR		= ar -rcs

SRC_FILES	= so_long.c \
			  so_long_utils.c

SRC_OBJ		= $(SRC_FILES:.c=.o)

SRC_DEPS	= $(SRC_FILES:.c=.d)

all: $(NAME) 

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compiling $<..."	

$(NAME) : $(SRC_OBJ) //he quitado comando AR, mirar
	@$(CC) $(SRC_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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
