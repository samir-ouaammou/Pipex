/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:41:27 by yourlogin         #+#    #+#             */
/*   Updated: 2024/12/13 21:42:41 by yourlogin        ###   ########.ch       */
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
char	*ft_strcat(char *dst, const char *src);
void	ft_msg_error(char *msg, char *error, int n);
void	ft_check_env(int ac, char **av, char **env, int i);

#endif

/*
#define OPEN_ERROR 1         // Error opening file
#define ENV_ERROR 2          // Error with environment variables
#define INVALID_ARGS 3       // Invalid number of arguments
#define MALLOC_ERROR 4       // Memory allocation failure
#define PIPE_ERROR 5         // Pipe creation failure
#define FORK_ERROR 6         // Fork creation failure
#define DUP2_ERROR 7         // Failure in file descriptor redirection using dup2
#define ACCESS_ERROR 8       // File access failure
#define EXECVE_ERROR 9       // execve execution failure
#define CMD_NOT_FOUND 127    // Command not found

*/