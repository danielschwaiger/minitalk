/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/20 18:23:41 by dapanciu         ###   ########.fr       */
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
	ft_printf("Hello from SERVER side!!!\n");
	ft_printf("len of printff = %zu\n", ft_strlen("Hello from SERVER side!!!"));
	return (0);
}
