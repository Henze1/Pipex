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
	char	*path;
	char	**command;

	command = ft_split(arg, ' ');
	if (contains(command[0], '/'))
		path = ft_strdup(arg);
	else
		path = get_path(command[0], envp);
	if (!path)
	{
		print_not_found(command[0]);
		spare_mem(&command);
		exit(1);
	}
	if (execve(path, command, envp) == -1)
	{
		print_not_found(command[0]);
		free(path);
		spare_mem(&command);
		exit(1);
	}
	spare_mem(&command);
	free(path);
}

char	*get_path(char *command, char **envp)
{
	int		i;
	char	*path;
	char	**root_path;

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
	free(root_path);
	return (NULL);
}

void	print_error(void)
{
	perror("Error");
	exit(1);
}

void	print_not_found(char *command)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(": command not found", 2);
}

void	spare_mem(char ***strs)
{
	int	i;

	if (!strs || !*strs)
		return ;
	i = -1;
	while ((*strs)[++i])
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
	}
	free(*strs);
	*strs = NULL;
}
