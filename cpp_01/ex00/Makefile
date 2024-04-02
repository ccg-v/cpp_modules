# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:52:49 by ccarrace          #+#    #+#              #
#    Updated: 2024/04/03 00:01:39 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #
 
CC 			= 	c++
NAME 		= 	brainz.out
FLAGS 		=	-Wall -Wextra -Werror -std=c++98

# --- Folders ---------------------------------------------------------------- #

INC_DIR		=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

# --- Includes --------------------------------------------------------------- #

INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #

SRC_FILES	=	newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o are treated as literal strings
DEP_FILES	=	$(OBJ_FILES:%.o=%.d)	# .o and .d are treated as patterns

# --- Files full paths ------------------------------------------------------- #

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))	
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(OBJ_DIR), $(DEP_FILES))

# --- Compilation rules ------------------------------------------------------ #

all: $(NAME) 

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEP)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

# --- Cleaning rules ---------------------------------------------------------- #

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re