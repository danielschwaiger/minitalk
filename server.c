/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/26 20:59:41 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "libft.h"
#include "ft_printf.h"

//TODO implement malloc !! 
// TODO implement a function to printout the received string !! GNL ??? 
// pass the norminette !! 

static void receive_signal(int signal)
{
	static int bit;
	static int n;

	if (signal == SIGUSR1)
		n |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		// implement memset ? 
		ft_printf("%c", n);
		bit = 0;
		n = 0;
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Please, run server without any arguments!\n");
		return (0);
	}
	ft_printf("Server running (PID : %d):\n", getpid());
	while(1)
	{
		signal(SIGUSR1, receive_signal);
		signal(SIGUSR2, receive_signal);
		pause ();
	}
	return (0);
}
