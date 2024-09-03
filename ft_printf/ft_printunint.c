/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:34:49 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 15:35:02 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_printunint(nbr / 10);
	count += ft_printchar((nbr % 10) + '0');
	return (count);
}
