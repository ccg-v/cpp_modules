# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 12:26:59 by ccarrace          #+#    #+#              #
#    Updated: 2024/03/15 19:13:53 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #

CC 			= 	c++
NAME 		= 	phonebook
FLAGS 		=	-Wall -Wextra -Werror -std=c++98

# --- Folders ---------------------------------------------------------------- #

INC_DIR		=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

# --- Includes --------------------------------------------------------------- #

INCLUDES	=	-I $(INC_DIR)

# --- Files ------------------------------------------------------------------ #

SRC_FILES	=	Accessors.cpp Contact.cpp PhoneBook.cpp
SRC			=	

# --- Macros ----------------------------------------------------------------- #

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)
DEP_FILES	=	$(SRC_FILES:.cpp=.d)

# --- Compilation rules ------------------------------------------------------ #

all:
			$(MAKE) $(NAME)

$(NAME): 	$(OBJ_FILES)
			$(CC) $(FLAGS) $(INCLUDES) $(OBJ_FILES) -o @

%.o: %.c Makefile
			$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP_FILES)

#