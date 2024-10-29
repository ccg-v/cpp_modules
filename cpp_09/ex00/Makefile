# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 21:59:21 by ccarrace          #+#    #+#              #
#    Updated: 2024/10/29 22:28:01 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #

NAME 		= 	btc

# --- Compiler --------------------------------------------------------------- #

CC 			= 	c++
FLAGS 		=	-MMD -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

# --- Folders ---------------------------------------------------------------- #

INC_DIR		=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/
DEP_DIR		=	$(OBJ_DIR)

# --- Includes --------------------------------------------------------------- #

INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #

SRC_FILES	=	BitcoinExchange.cpp DateUtils.cpp main.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o are treated as literal strings
DEP_FILES	=	$(OBJ_FILES:%.o=%.d)	# .o and .d are treated as patterns

# --- Files full paths ------------------------------------------------------- #

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			=	$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Build rules ------------------------------------------------------------ #

all: $(OBJ_DIR) $(NAME) 

# --- Object build rules ----------------------------------------------------- #

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
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