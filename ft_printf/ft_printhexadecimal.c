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

int	ft_printhexadecimal(unsigned int n, char f)
{
	int		i;
	int		len;
	char	numarr[16];

	if (!n)
		return (ft_printchar('0'));
	i = 0;
	len = 0;
	while (n)
	{
		if (n % 16 >= 10)
		{
			if (f == 'x')
				numarr[i++] = n % 16 - 10 + 'a';
			else
				numarr[i++] = n % 16 - 10 + 'A';
		}
		else
			numarr[i++] = n % 16 + '0';
		++len;
		n /= 16;
	}
	while (i--)
		ft_printchar(numarr[i]);
	return (len);
}
