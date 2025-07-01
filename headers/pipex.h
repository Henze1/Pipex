/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:43:09 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/29 11:59:37 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

int		main(int argc, char **argv, char **envp);
void	pipex(char **argv, char **envp);
void	print_error(void);
void	print_not_found(char *command);
void	process_input(int *fd, char **argv, char **envp);
void	process_output(int *fd, char **argv, char **envp);
void	exec_bash(char *arg, char **envp);
char	*get_path(char *command, char **envp);
int		is_only_space(char const *str);
int		contains(char const *str, char c);
void	spare_mem(char ***strs);

#endif
