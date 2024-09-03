/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:34:07 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:24:01 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr, char *str, int i, int check)
{
	int	count;

	count = 0;
	if (nbr >= 0 && check == 1 && (str[i - 1] == ' ' || str[i - 1] == '+'))
		count += ft_printchar(str[i - 1]);
	check = 0;
	if (nbr == -2147483648)
	{
		count += ft_printchar('-');
		count += ft_printchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		count += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		count += ft_printnbr(nbr / 10, str, i, check);
	count += ft_printchar((nbr % 10) + '0');
	return (count);
}
