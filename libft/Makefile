# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:59:57 by conguyen          #+#    #+#              #
#    Updated: 2021/12/16 12:51:37 by conguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES += ft_strchr.c
CFILES += ft_strdel.c
CFILES += ft_strdup.c
CFILES += ft_strjoin.c
CFILES += ft_strsub.c
CFILES += ft_strnew.c
CFILES += ft_strcat.c
CFILES += ft_strlen.c
CFILES += ft_bzero.c
CFILES += ft_strcpy.c

OBJ = $(CFILES:.c=.o)
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -I includes $(CFLAGS) $(CFILES)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
