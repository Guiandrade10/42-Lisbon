/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:34:24 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:05:23 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlong(unsigned long nbr, char *base);

int	ft_printptr(unsigned long nbr, char *base)
{
	int	count;

	if (nbr == 0)
		return (ft_printstr("(nil)"));
	count = 0;
	count += ft_printstr("0x");
	count += ft_hexlong(nbr, base);
	return (count);
}

static int	ft_hexlong(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr > 15)
		count += ft_hexlong(nbr / 16, base);
	count += ft_printchar(base[nbr % 16]);
	return (count);
}
