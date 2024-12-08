# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 21:32:46 by souaammo          #+#    #+#              #
#    Updated: 2024/12/08 21:32:49 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	ft_pipex.c	ft_pipex_utils1.c	ft_pipex_utils2.c

OBJS = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
