/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/23 15:28:01 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// this function will check if server receives sigusr1 or sigusr2.
static void client_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("\e[33m## Succes - SIGUSR1 is AKC by the server ##\n\e[0m", STDOUT_FILENO);		
	}
	else if (signal == SIGUSR2)
	{
		ft_putstr_fd("\e[33m## Succes - SIGUSR2 is AKC by the server ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static  void send_client_message(int server_pid, char *str)
{
	int i;

	i = 0;

	send_str_len(server_pid, ft_strlen(str));
	// check if null has been sent.
	// send_char
}

int	main(int argc, char **argv)
{
	struct sigaction pa_client;
	
	if (argc != 3)
	{
		ft_putstr_fd("\e[33m## error - incorrect arguments! ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd("\e[31m./client <the server PID> <the string to send>\n\e[0m",STDOUT_FILENO);
		return (EXIT_FAILURE);
	}	
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[33m## error - INVALID PID ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	sigemptyset(&pa_client.sa_mask);
	pa_client.sa_flags = SA_RESTART;
	pa_client.sa_handler = client_handler;
	// configure a custom handler to catch and strout error messages in case that communication fails.
	signals_configuration_sigaction(&pa_client);
	send_client_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}

