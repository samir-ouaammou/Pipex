# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 19:57:28 by souaammo          #+#    #+#              #
#    Updated: 2024/12/11 19:57:30 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	ft_pipex.c	ft_pipex_utils1.c	ft_pipex_utils2.c	ft_pipex_utils3.c	get_next_line.c	get_next_line_utils.c

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
