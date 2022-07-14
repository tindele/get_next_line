# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 13:31:19 by chpenzko          #+#    #+#              #
#    Updated: 2022/07/14 14:08:08 by chpenzko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=get_next_line.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=get_next_line_utils.c get_next_line.c 
OBJ=*.o

all: $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all re