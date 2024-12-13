/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:34:08 by yourlogin         #+#    #+#             */
/*   Updated: 2024/12/13 21:39:38 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_get_cmd_path(char *cmd)
{
	char	*cmd_path;

	cmd_path = malloc(ft_strlen("/usr/bin/") + ft_strlen(cmd) + 1);
	if (!cmd_path)
		ft_msg_error("Malloc error\n", NULL, 4);
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
		ft_msg_error("Malloc error\n", NULL, 4);
	path = ft_get_cmd_path(args[0]);
	if (!path)
		ft_msg_error("Commont not found: ", cmd, 127);
	if (execve(path, args, NULL) == -1)
		ft_msg_error("Execve error\n", NULL, 8);
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
		ft_msg_error("Pipe error\n", NULL, 5);
	pid = fork();
	if (pid < 0)
		ft_msg_error("Fork error\n", NULL, 6);
	if (pid == 0)
	{
		dup2(fd2, 1);
		dup2(pipefd[0], 0);
		ft_close(pipefd[1], pipefd[0]);
		ft_run_cmd(cmd2);
		exit(0);
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
		ft_msg_error("Invalid number of arguments\n", NULL, 2);
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		ft_msg_error("Input file open error\n", NULL, 1);
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 == -1)
		ft_msg_error("output file open error\n", NULL, 1);
	ft_pipex(fd1, av[2], av[3], fd2);
	close(fd1);
	close(fd2);
	exit(0);
}
