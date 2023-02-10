# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:19:06 by sben-ela          #+#    #+#              #
#    Updated: 2023/02/10 17:20:16 by aybiouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
PROG = mini_shell
LIBFT = Libft/libft.a
SOURCES = mini_shell.c ft_split.c utils.c ft_execute.c $(LIBFT)

OBJECTS = $(SOURCES:.c=.o)

all : $(PROG)
$(LIBFT) :
	make -C libft
$(PROG) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lreadline -o $(PROG)
	rm -f $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(PROG)

bonus: all
	ar rc $(NAME)

re: fclean all
