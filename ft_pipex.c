/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:31:53 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/08 22:54:38 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_get_cmd_path(char *cmd)
{
	char	*cmd_path;

	cmd_path = malloc(ft_strlen("/usr/bin/") + ft_strlen(cmd) + 1);
	if (!cmd_path)
		ft_error("Malloc error");
	cmd_path[0] = '\0';
	ft_strcat(cmd_path, "/usr/bin/");
	ft_strcat(cmd_path, cmd);
	if (access(cmd_path, F_OK) == 0)
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
		ft_error("Commont not found");
	if (execve(path, args, NULL) == -1)
		ft_error("Execve error");
	free(path);
}

void	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	ft_pipex(int fd1, char *cmd1, char *cmd2, int fd2)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid < 0)
		ft_error("Fork error");
	if (pid == 0)
	{
		dup2(fd2, 1);
		dup2(pipefd[0], 0);
		ft_close(pipefd[1], pipefd[0]);
		ft_run_cmd(cmd2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		dup2(fd1, 0);
		dup2(pipefd[1], 1);
		ft_close(pipefd[1], pipefd[0]);
		ft_run_cmd(cmd1);
		wait(NULL);
	}
	ft_close(pipefd[1], pipefd[0]);
}

int	main(int ac, char **av)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
	{
		write(1, "Invalid number of arguments\n", 28);
		exit(EXIT_FAILURE);
	}
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		ft_error("Input file open error");
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 == -1)
		ft_error("output file open error");
	ft_pipex(fd1, av[2], av[3], fd2);
	close(fd1);
	close(fd2);
	exit(EXIT_SUCCESS);
}
