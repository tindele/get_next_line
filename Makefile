# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 13:31:19 by chpenzko          #+#    #+#              #
#    Updated: 2022/07/14 13:43:59 by chpenzko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=get_next_line.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=get_next_line_utils.c get_next_line.c 
OBJ=*.o

s $(NAME)
all
clean
fclean
re