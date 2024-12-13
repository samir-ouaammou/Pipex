/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:33:48 by yourlogin         #+#    #+#             */
/*   Updated: 2024/12/13 21:33:51 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dst, const char *src);
void	ft_msg_error(char *msg, char *error, int n);

#endif
