# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 10:12:26 by ccarrace          #+#    #+#              #
#    Updated: 2024/05/20 01:26:23 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #
CC			=	c++
NAME		=	animal.out
FLAGS		=	-Wall -Wextra -Werror -std=c++98

# --- Folders ---------------------------------------------------------------- #

INC_DIR		=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

# --- Includes --------------------------------------------------------------- #

INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #

SRC_FILES	=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o are treated as literal strings
DEP_FILES	=	$(OBJ_FILES:%.o=%.d)	# .o and .d are treated as patterns

# --- Files full paths ------------------------------------------------------- #

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Compilation rules ------------------------------------------------------ #

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEP)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# --- Cleaning rules --------------------------------------------------------- #

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re