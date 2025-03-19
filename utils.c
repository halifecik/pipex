/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:03:43 by hademirc          #+#    #+#             */
/*   Updated: 2025/03/19 23:04:59 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_handle_error(int val)
{
	if (val == 1)
		ft_putstr_fd("USAGE: ./pipex infile '/cmd1' '/cmd2' outfile\n", 2);
	exit(0);
}

int	ft_open_file(char *file, int val)
{
	int	rtn;

	if (val)
		rtn = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		rtn = open(file, O_RDONLY);
	if (val < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(file);
		exit(1);
	}
	return (rtn);
}

char	*ft_get_path(char **ep)
{
	int		i;
	char	*path;

	path = NULL;
	i = -1;
	while (ep[++i])
	{
		if (!ft_strncmp(ep[i], "PATH=", 5))
		{
			path = ep[i] + 5;
			break ;
		}
	}
	if (!path)
		exit(1);
	return (path);
}

char	*ft_get_cmd(char *cmd, char **ep)
{
	char	**path;
	char	*part;
	char	**opt;
	char	*exec;
	int		i;

	i = -1;
	path = ft_split(ft_get_path(ep), ':');
	opt = ft_split(cmd, ' ');
	while (path[++i])
	{
		part = ft_strjoin(path[i], "/");
		exec = ft_strjoin(part, opt[0]);
		free(part);
		if (!access(exec, F_OK | X_OK))
		{
			ft_free_tab(opt);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(path);
	ft_free_tab(opt);
	return (cmd);
}
