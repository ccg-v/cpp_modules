# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 23:35:07 by ccarrace          #+#    #+#              #
#    Updated: 2024/08/18 20:23:05 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #

NAME 		= 	convert

# --- Compiler --------------------------------------------------------------- #

CC 			= 	c++
FLAGS 		=	-MMD -Wall -Wextra -Werror -std=c++98

# --- Folders ---------------------------------------------------------------- #

INC_DIR		=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/
DEP_DIR		=	$(OBJ_DIR)

# --- Includes --------------------------------------------------------------- #

INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #

SRC_FILES	=	toChar.cpp toInt.cpp toFloat.cpp toDouble.cpp main.cpp \
				ScalarConverter.cpp ScalarExceptions.cpp
				
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o treated as literal strings
DEP_FILES	=	$(SRC_FILES:.cpp=.d)	

# --- Files full paths ------------------------------------------------------- #

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Build rules ------------------------------------------------------------ #

all: $(OBJ_DIR) $(NAME) 

# --- Object build rules ----------------------------------------------------- #

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

# --- Program build rules ---------------------------------------------------- #
$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY:	all clean fclean re
