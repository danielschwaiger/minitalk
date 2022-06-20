/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:41:28 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/20 18:14:39 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*--------------Specifier---------------*/
int	ft_printf(char const *frmt, ...);
int	ft_read_types(va_list ap, char c);
/*--------------Other functions---------------*/
int	ft_print_hexa(unsigned long int nb, char c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);

#endif
