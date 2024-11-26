# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 21:59:21 by ccarrace          #+#    #+#              #
#    Updated: 2024/11/27 00:30:23 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #
NAME 		= 	PmergeMe

# --- Compiler --------------------------------------------------------------- #
CXX 		= 	c++
CXXFLAGS 	=	-MMD -Wall -Wextra -Werror -std=c++98 -g #-DDEBUG_MODE

# --- Folders ---------------------------------------------------------------- #
INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
DEP_DIR		=	$(OBJ_DIR)

# --- Includes --------------------------------------------------------------- #
INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #
SRC_FILES	=	PmergeMe.cpp Utils.cpp main.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o are treated as literal strings
DEP_FILES	=	$(OBJ_FILES:%.o=%.d)	# .o and .d are treated as patterns

# --- Files full paths ------------------------------------------------------- #
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Build rules ------------------------------------------------------------ #
all: $(OBJ_DIR) $(NAME)

# --- Object build rules ----------------------------------------------------- #
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
-include $(DEP)

# --- Program build rules ---------------------------------------------------- #
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY:	all clean fclean re//