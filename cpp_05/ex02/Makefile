# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 23:35:07 by ccarrace          #+#    #+#              #
#    Updated: 2024/07/21 20:12:43 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #

NAME 		= 	form.out

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

SRC_FILES	=	Bureaucrat.cpp AForm.cpp main.cpp 
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o treated as literal strings
DEP_FILES	=	$(SRC_FILES:.cpp=.d)	

# --- Files full paths ------------------------------------------------------- #

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Build rules ------------------------------------------------------------ #

all: $(NAME) 

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
