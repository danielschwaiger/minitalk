/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/20 18:21:49 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>
#include "minitalk.h"
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello from CLIENT side!!!\n");
	ft_printf("CLIENT COUNT = %zu\n", ft_strlen("TESTING"));
	ft_putnbr_fd(100, 3);
	return (0);
}
