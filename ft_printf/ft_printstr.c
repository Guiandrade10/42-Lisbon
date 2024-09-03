/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:34:38 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:46:42 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	if (!s)
		return (ft_printstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_printchar(s[i]);
		i++;
	}
	return (i);
}
