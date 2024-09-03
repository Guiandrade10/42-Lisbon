/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:33:51 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:22:12 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int nbr, char *str, int i, int check)
{
	int	count;

	count = 0;
	if (nbr != 0 && str[i - 1] == '#' && check == 1)
	{
		if (str[i] == 'x')
			count += ft_printstr("0x");
		else
			count += ft_printstr("0X");
	}
	check = 0;
	if (str[i] == 'X')
	{
		if (nbr > 15)
			count += ft_printhex(nbr / 16, str, i, check);
		count += ft_printchar("0123456789ABCDEF"[nbr % 16]);
	}
	else
	{
		if (nbr > 15)
			count += ft_printhex(nbr / 16, str, i, check);
		count += ft_printchar("0123456789abcdef"[nbr % 16]);
	}
	return (count);
}
