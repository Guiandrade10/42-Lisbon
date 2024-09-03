/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:30:49 by gude-and          #+#    #+#             */
/*   Updated: 2024/08/30 16:16:07 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printptr(unsigned long nbr, char *base);
int	ft_printnbr(int nbr, char *str, int index, int flag_check);
int	ft_printunint(unsigned int nbr);
int	ft_printhex(unsigned int nbr, char *str, int index, int hash_check);

#endif
