/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/19 19:43:36 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "server.h"
#include "libft.h"
#include "ft_printf.h"

//TODO implement malloc !! 
// TODO implement a function to printout the received string !!
// pass the norminette !! 

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

static void receive_signal(int signal)
{
	static int bit;
	static int n;

	if (signal == SIGUSR1) // checks if signal id is the same as SISGUSR1 to continue !
		n |= (1 << bit); // n = n | (1<< bit); moves one byte to the left ?? 
	bit++;
	if (bit == 8)
	{
		/* ft_printf("%c", n); create a function to capture each byte and convert it into a string !*/
		if(n != '\0')
		{
			ft_printf("%c", n);
		}
		bit = 0;
		n = 0;
	}
}
