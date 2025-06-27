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

static int	write_hex(void *p);

int	ft_printaddr(void *p)
{
	int	len;

	len = 0;
	if (!p)
		len += ft_printstring("(nil)");
	else
	{
		len += ft_printchar('0');
		len += ft_printchar('x');
		len += write_hex(p);
	}
	return (len);
}

static int	write_hex(void *p)
{
	int					i;
	int					len;
	unsigned long long	ptr;
	char				numarr[16];

	i = 0;
	len = 0;
	ptr = (unsigned long long)p;
	while (ptr)
	{
		if (ptr % 16 >= 10)
			numarr[i++] = ptr % 16 - 10 + 'a';
		else
			numarr[i++] = ptr % 16 + '0';
		++len;
		ptr /= 16;
	}
	while (i--)
		ft_printchar(numarr[i]);
	return (len);
}
