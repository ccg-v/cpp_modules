# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 23:35:07 by ccarrace          #+#    #+#              #
#    Updated: 2024/08/02 19:16:51 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program name ----------------------------------------------------------- #
NAME 		= 	bureaucrat.out

# --- Compiler --------------------------------------------------------------- #
CC 			= 	c++
FLAGS 		=	-MMD -Wall -Wextra -Werror -std=c++98

# --- Files ------------------------------------------------------------------ #
SRC_FILES	=	Bureaucrat.cpp Form.cpp main.cpp 
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)	# .cpp and .o are treated as literal strings
DEP_FILES	=	$(OBJ_FILES:%.o=%.d)	# .o and .d are treated as patterns

# --- Build rules ------------------------------------------------------------ #
all: $(NAME) 

# --- Object build rules ----------------------------------------------------- #
%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

-include $(DEP_FILES)

# --- Program build rules ---------------------------------------------------- #
$(NAME): $(OBJ_FILES) Makefile
	$(CC) $(FLAGS) $(OBJ_FILES) -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
	rm -f $(OBJ_FILES)
	rm -f $(DEP_FILES)
	
fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY:	all clean fclean re
