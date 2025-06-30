/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:44:08 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/29 11:59:36 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	child_pid1;
	pid_t	child_pid2;

	if (pipe(fd) == -1)
		print_error();
	child_pid1 = fork();
	if (child_pid1 == -1)
		print_error();
	else if (child_pid1 == 0)
		process_input(fd, argv, envp);
	else
	{
		child_pid2 = fork();
		if (child_pid2 == -1)
			print_error();
		else if (child_pid2 == 0)
			process_output(fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
}

void	process_input(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[0], O_RDONLY, 0664);
	if (file == -1)
		print_error();
	dup2(fd[1], 1);
	dup2(file, 0);
	close(fd[0]);
	exec_bash(argv[1], envp);
}

void	process_output(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file == -1)
		print_error();
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[1]);
	exec_bash(argv[2], envp);
}
