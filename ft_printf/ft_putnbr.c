/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:04:18 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/26 16:44:34 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	dest;

	dest = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		dest += write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		dest += ft_putnbr(nb / 10);
	}
	nb = nb % 10;
	if (nb < 10)
		dest += ft_putchar(nb + 48);
	return (dest);
}
