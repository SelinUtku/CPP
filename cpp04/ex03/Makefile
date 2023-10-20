# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 16:03:37 by sutku             #+#    #+#              #
#    Updated: 2023/10/18 17:56:27 by sutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.SILENT:

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC		=	main.cpp AMateria.cpp MateriaSource.cpp \
			Character.cpp Cure.cpp Ice.cpp
OBJ		=	$(SRC:.cpp=.o)

CC		= 	c++
RM		=   rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	materials

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	echo "$(CYAN)Ex03 compiled successfully$(DEF_COLOR)"

clean:
	$(RM) $(OBJ)
	echo "$(MAGENTA)Object-Files are cleaned$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	echo "$(MAGENTA)Programs / Libraries are cleaned!$(DEF_COLOR)"
	
re: fclean all

.PHONY: all clean fclean re