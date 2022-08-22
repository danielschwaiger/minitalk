/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/22 11:45:19 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	(void)argv; // !!!!
	sigset_t block;
	
	if (argc != 1)
	{
		ft_putstr_fd("\e[33m## error - Please run server without any arguments! ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("\e[32m## SUCCES! ##\n\e[0m", STDOUT_FILENO);
	ft_printf("\e[31m Server running (PID : %d):\n", getpid());
	// we cancel signals like SIGTERM or SIGINT as we dont want our program to end while waiting in standby for string messages!
	sigemptyset(&block);
	sigaddset(&block, SIGTERM);
	sigaddset(&block, SIGINT);

	
	while(1)
	{
		while(1)
		{
			ft_printf("\e[32m Waiting for messages: \n");
			break ;
		}
		pause();
	}
	return (EXIT_SUCCESS);
}

