/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:59:32 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/20 13:31:19 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Deberá implementar las siguientes conversiones: cspdiuxX %. */

int	ft_read_types(va_list ap, char x)
{
	int	i;

	i = 0;
	if (x == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (x == '%')
		i += ft_putchar('%');
	else if (x == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (x == 'd' || x == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (x == 'p')
		i += ft_putstr("0x") + ft_print_hexa(va_arg(ap, unsigned long int), x);
	else if (x == 'x' || x == 'X')
		i += ft_print_hexa(va_arg(ap, unsigned int), x);
	else
		if (x == 'u')
			i += ft_putnbr_u(va_arg(ap, unsigned int));
	return (i);
}

int	ft_printf(char const *frmt, ...)
{
	va_list				pd;
	int					i;

	i = 0;
	va_start(pd, frmt);
	while (*frmt != '\0')
	{
		if (*frmt == '%')
			i += ft_read_types(pd, *++frmt);
		else
			i += ft_putchar(*frmt);
		frmt++;
	}
	va_end(pd);
	return (i);
}
