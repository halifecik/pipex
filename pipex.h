/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:06:49 by hademirc          #+#    #+#             */
/*   Updated: 2025/03/19 23:07:09 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_free_tab(char **tab);
char	*ft_get_path(char **ep);
void	ft_handle_error(int val);
char	*ft_get_cmd(char *cmd, char **ep);
int		ft_open_file(char *file, int val);

#endif