# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:19:06 by sben-ela          #+#    #+#              #
#    Updated: 2023/02/09 15:59:22 by sben-ela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
NAME = mini_shell.a
PROG = mini_shell
SOURCES = mini_shell.c ft_split.c utils.c

OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	cc $(CFLAGS) $(NAME) -lreadline -o $(PROG)
	rm -f $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(PROG)

bonus: all
	ar rc $(NAME)

re: fclean all
