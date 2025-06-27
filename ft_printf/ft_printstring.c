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

int	ft_printstring(char *str)
{
	int	i;

	if (!str)
		return (ft_printstring("(null)"));
	i = 0;
	while (str[i])
		i += ft_printchar(str[i]);
	return (i);
}
