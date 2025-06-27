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

int	ft_printunsigned(unsigned int n)
{
	int		i;
	int		len;
	char	numarr[16];

	if (!n)
	{
		ft_printchar('0');
		return (1);
	}
	i = 0;
	len = 0;
	while (n)
	{
		numarr[i++] = n % 10 + '0';
		++len;
		n /= 10;
	}
	while (i--)
		ft_printchar(numarr[i]);
	return (len);
}
