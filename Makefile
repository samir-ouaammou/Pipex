# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:10:18 by souaammo          #+#    #+#              #
#    Updated: 2024/12/13 12:41:03 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_pipex.c ft_pipex_utils1.c ft_pipex_utils2.c

BONUS = ft_pipex_bonus.c ft_pipex_utils1_bonus.c ft_pipex_utils2_bonus.c \
        ft_pipex_utils3_bonus.c get_next_line.c get_next_line_utils.c

OBJS = $(FILES:.c=.o)
BOBJS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
