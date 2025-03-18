# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 13:44:07 by nlewicki          #+#    #+#              #
#    Updated: 2025/03/18 13:45:03 by nlewicki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Mutant
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++17

SRC_FILES	= main.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
