# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:19:06 by sben-ela          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/02/11 12:38:26 by aybiouss         ###   ########.fr        #
=======
#    Updated: 2023/02/10 20:42:40 by sben-ela         ###   ########.fr        #
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
PROG = mini_shell
LIBFT = Libft/libft.a
SOURCES = mini_shell.c ft_split.c utils.c ft_execute.c parse_redirect.c  ft_error.c handle_couts.c $(LIBFT)

OBJECTS = $(SOURCES:.c=.o)

all : $(PROG)
$(LIBFT) :
	make -C libft
$(PROG) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lreadline -o $(PROG)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(PROG) $(LIBFT)

bonus: all
	ar rc $(NAME)

re: fclean all
