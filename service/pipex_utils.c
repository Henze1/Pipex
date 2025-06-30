/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:37:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/30 14:32:49 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	exec_bash(char *arg, char **envp)
{
	int		i;
	char	*path;
	char	**command;

	i = 0;
	command = ft_split(arg, ' ');
	if (!command)
		exit(1);
	path = get_path(command[0], envp);
	if (!path)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		free(path);
		print_error();
	}
	if (execve(path, command, envp) == -1)
	{
		free(path);
		print_error();
	}
}

char	*get_path(char *command, char **envp)
{
	int		i;
	char	**root_path;
	char	*path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		++i;
	root_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (root_path[i])
	{
		path = ft_strjoin(root_path[i++], "/");
		path = ft_strjoin(path, command);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	i = 0;
	free(root_path);
	return (NULL);
}

void	print_error(void)
{
	perror("Error");
	exit(1);
}
