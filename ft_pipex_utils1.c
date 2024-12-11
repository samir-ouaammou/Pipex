/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:56:23 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/11 19:56:24 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_error(char *msgerror)
{
	perror(msgerror);
	exit(EXIT_FAILURE);
}

void	free_split_array(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	*ft_get_cmd_path(char *cmd)
{
	char	*cmd_path;

	cmd_path = malloc(ft_strlen("/usr/bin/") + ft_strlen(cmd) + 1);
	if (!cmd_path)
		ft_error("Malloc error");
	cmd_path[0] = '\0';
	ft_strcat(cmd_path, "/usr/bin/");
	ft_strcat(cmd_path, cmd);
	if (access(cmd_path, F_OK | X_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	return (NULL);
}

void	ft_run_cmd(char *cmd)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		ft_error("Malloc error");
	path = ft_get_cmd_path(args[0]);
	if (!path)
	{
		free_split_array(args);
		ft_error("Command not found");
	}
	if (execve(path, args, NULL) == -1)
	{
		free(path);
		free_split_array(args);
		ft_error("Execve error");
	}
}

void	ft_check_env(int ac, char **av, char **env, int i)
{
	if (*env != NULL)
		return ;
	while (i < ac - 1)
	{
		write(2, "Command not found: ", 19);
		write(2, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i++;
	}
	exit(EXIT_FAILURE);
}
