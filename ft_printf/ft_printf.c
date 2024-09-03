/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:21:40 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:21:00 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg(va_list list, char *str, int i);

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	int		i;

	if (str == NULL)
		return (-1);
	va_start(list, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] != 'c' && str[i] != 's' && str[i] != 'p'
				&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
				i++;
			count += arg(list, (char *)str, i);
		}
		else
			count += ft_printchar(str[i]);
	}
	va_end(list);
	return (count);
}

static int	arg(va_list list, char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_printchar(va_arg(list, int));
	else if (str[i] == 's')
		count += ft_printstr(va_arg(list, char *));
	else if (str[i] == 'p')
		count += ft_printptr(va_arg(list, unsigned long), "0123456789abcdef");
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_printnbr(va_arg(list, int), str, i, 1);
	else if (str[i] == 'u')
		count += ft_printunint(va_arg(list, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_printhex(va_arg(list, unsigned int), str, i, 1);
	else if (str[i] == '%')
		count += ft_printchar(str[i]);
	return (count);
}
