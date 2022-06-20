/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:33:13 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/26 16:32:27 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long int nb, char c)
{
	int	res;

	res = 0;
	if (c == 'x' || c == 'p')
	{
		if (nb >= 16)
			res = ft_print_hexa(nb / 16, c);
		res += ft_putchar("0123456789abcdef"[nb % 16]);
	}
	else if (c == 'X')
	{
		if (nb >= 16)
			res = res + ft_print_hexa(nb / 16, c);
		res = res + ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	return (res);
}
