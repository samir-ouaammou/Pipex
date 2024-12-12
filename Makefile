# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:10:18 by souaammo          #+#    #+#              #
#    Updated: 2024/12/12 13:10:21 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_pipex1.c ft_pipex1_utils1.c ft_pipex1_utils2.c

BONUS = ft_pipex2_bonus.c ft_pipex2_utils1_bonus.c ft_pipex2_utils3_bonus.c \
        ft_pipex2_utils2_bonus.c get_next_line.c get_next_line_utils.c

OBJS = $(FILES:.c=.o)

BOBJS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
BONUS_NAME = pipex_bonus

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BONUS_NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all
