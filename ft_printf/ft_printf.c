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

#include "ft_printf.h"

static int	formater(va_list args, char f);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += formater(args, s[i + 1]);
			++i;
		}
		else
			len += ft_printchar(s[i]);
		++i;
	}
	va_end(args);
	return (len);
}

static int	formater(va_list args, char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (f == 's')
		len += ft_printstring(va_arg(args, char *));
	else if (f == 'p')
		len += ft_printaddr(va_arg(args, void *));
	else if (f == 'd' || f == 'i')
		len += ft_printdecimal(va_arg(args, int));
	else if (f == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len += ft_printhexadecimal(va_arg(args, unsigned int), f);
	else if (f == '%')
		len += ft_printchar('%');
	return (len);
}
