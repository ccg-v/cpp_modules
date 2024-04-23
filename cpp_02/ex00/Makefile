# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 21:05:41 by ccarrace          #+#    #+#              #
#    Updated: 2024/04/23 21:06:43 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #
NAME 		= 	fixed.out

# --- Compiler --------------------------------------------------------------- #
CC 			= 	c++
FLAGS 		=	-Wall -Wextra -Werror -std=c++98 -g

# --- Files ------------------------------------------------------------------ #
SRC_FILES	=	Fixed.cpp main.cpp 
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

# --- Build rules ------------------------------------------------------------ #
all: $(NAME) 

# --- Object build rules ----------------------------------------------------- #
%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

# --- Program build rules ---------------------------------------------------- #
$(NAME): $(OBJ_FILES) Makefile
	$(CC) $(FLAGS) $(OBJ_FILES) -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re