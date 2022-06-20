/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:38:45 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/26 16:37:11 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	val;

	if (!s)
		return (ft_putstr("(null)"));
	val = 0;
	while (*s)
		val += ft_putchar(*s++);
	return (val);
}
