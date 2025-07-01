/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:28:58 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:18 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putendl_fd("Error: Invalid arguments\n", 2);
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	else if (!*argv[2] || is_only_space(argv[2])
		|| !*argv[3] || is_only_space(argv[3]))
	{
		ft_putendl_fd("Error: Invalid arguments\n", 2);
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	else
		pipex(++argv, envp);
	while (wait(NULL) != -1)
		;
	return (0);
}
