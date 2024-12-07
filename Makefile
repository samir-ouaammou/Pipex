# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:28:32 by souaammo          #+#    #+#              #
#    Updated: 2024/12/07 16:51:18 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_pipex.c ft_pipex_utils.c

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
