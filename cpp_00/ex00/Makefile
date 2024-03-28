# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:56:58 by ccarrace          #+#    #+#              #
#    Updated: 2024/03/28 20:07:05 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #

CC 			= 	c++
NAME 		= 	megaphone
FLAGS 		=	-Wall -Wextra -Werror -std=c++98

# --- Files ------------------------------------------------------------------ #

SRC			=	megaphone.cpp
OBJ			=	$(SRC:.cpp=.o)

# --- Compilation rules ------------------------------------------------------ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o: %.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

# --- Cleaning rules ---------------------------------------------------------- #

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re