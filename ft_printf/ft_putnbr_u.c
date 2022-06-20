/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:57:45 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/31 11:17:42 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	dest;

	dest = 0;
	if (nb >= 10)
		dest = ft_putnbr_u(nb / 10);
	nb = nb % 10;
	if (nb < 10)
		dest += ft_putchar(nb + '0');
	return (dest);
}
