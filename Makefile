# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:45:23 by laugarci          #+#    #+#              #
#    Updated: 2022/12/14 17:56:58 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.a

HEADER	= so_long.h
INCLUDE	= -I ./

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
AR		= ar -rcs

SRC_FILES	= so_long.c \

SRC_OBJ		= $(SRC_FILES:.c=.o)

SRC_DEPS	= $(SRC_FILES:.c=.d)

all: $(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compiling $<..."	

$(NAME) : $(SRC_OBJ)
	@$(AR) $(NAME) $(SRC_OBJ)
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
