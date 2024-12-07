/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:32:52 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/07 09:19:43 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int    ft_checkcmd(char *cmd)
{
    char    *temp;
    
    temp = malloc(10 + strlen(cmd));
    if (!temp)
        return (42);
    temp[0] = '\0';
    strcat(temp, "/usr/bin/");
    strcat(temp, cmd);
    if (access(temp, X_OK) < 0)
        return (42);
    return (1337);
}

int main(int ac, char **av)
{
    int     fds[2];
    int     fd1;
    int     fd2;
    pid_t   pid;

    if (ac < 5)
        return (printf("Error: (%s)\n", strerror(errno)), -1);

    if (access(av[1], F_OK) < 0)
        return (printf("Error: (%s)\n", strerror(errno)), -1);
    if (ft_checkcmd(av[2]) == 42)
        return (printf("Command not found: (%s)\n", av[2]), -1);
    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[4],O_CREAT, O_WRONLY);
    if (!fd1 || !fd2)
        return (printf("Error: (%s)\n", strerror(errno)), -1);
    if (pipe(fds) < 0)
        return (printf("Error: (%s)\n", strerror(errno)), -1);
}