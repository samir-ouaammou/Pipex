/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:49:22 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/13 21:49:24 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_msg_error(char *msg, char *error, int n)
{
	write(2, msg, ft_strlen(msg));
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	exit(n);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	if (!str)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	d_len;

	if (!dst || !src)
		return (NULL);
	d_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) + (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
