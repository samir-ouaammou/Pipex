/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:53:56 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/13 14:53:58 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# define BUFFER_SIZE 1

void	ft_run_cmd(char *cmd);
char	*get_next_line(int fd);
void	ft_close(int fd1, int fd2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	free_split_array(char **args);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_args(int ac, char **av);
char	**ft_split(char const *s, char c);
int		ft_strchr(const char *str, char c);
void	ft_msg_error(char *msg, char *error);
char	*ft_strcat(char *dst, const char *src);
void	ft_check_env(int ac, char **av, char **env, int i);

#endif
