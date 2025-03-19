/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:57:45 by hademirc          #+#    #+#             */
/*   Updated: 2025/03/19 23:03:29 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execute(char *cmd, char **ep)
{
	char	**commands;
	char	*path;

	commands = ft_split(cmd, ' ');
	path = ft_get_cmd(commands[0], ep);
	if (execve(path, commands, ep) == -1)
	{
		ft_putstr_fd(commands[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_tab(commands);
		exit(0);
	}
}

static void	ft_child(char **argv, int *fd, char **ep)
{
	int	file_descriptor;

	file_descriptor = ft_open_file(argv[1], 0);
	dup2(file_descriptor, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	ft_execute(argv[2], ep);
}

static void	ft_parent(char **argv, int *fd, char **ep)
{
	int	file_descriptor;

	file_descriptor = ft_open_file(argv[4], 1);
	dup2(file_descriptor, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	ft_execute(argv[3], ep);
}

int	main(int argc, char **argv, char **ep)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_handle_error(1);
	if (pipe(fd) < 0)
		exit(-1);
	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid == 0)
		ft_child(argv, fd, ep);
	ft_parent(argv, fd, ep);
	return (0);
}
