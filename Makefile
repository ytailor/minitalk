#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 12:01:49 by ytailor           #+#    #+#              #
#    Updated: 2014/02/08 17:29:53 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = client

NAME2 = serveur

FLAGS = -Wall -Wextra -Werror

SRCS_SERVEUR  =	ft_serveur.c \
				ft_list.c

SRCS_CLIENT = ft_client.c

OBJS_S = $(SRCS_SERVEUR:.c=.o)

OBJS_C = $(SRCS_CLIENT:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJS_C)
	make -C libft
	gcc $(FLAGS) $(SRCS_CLIENT) -o $(NAME) libft/libft.a

$(NAME2): $(OBJS_S)
	gcc $(FLAGS) $(SRCS_SERVEUR) -o $(NAME2) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_S)
	rm -f $(OBJS_C)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re

