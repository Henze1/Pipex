/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:47:52 by hpodratc          #+#    #+#             */
/*   Updated: 2025/01/20 09:48:13 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(unsigned char c);
int	ft_printstring(char *str);
int	ft_printaddr(void *p);
int	ft_printdecimal(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhexadecimal(unsigned int n, char f);

#endif
