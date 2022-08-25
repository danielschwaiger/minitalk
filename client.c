/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/25 15:45:47 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR1_IS_0)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",
			STDOUT_FILENO);
	else if (sig == SIGUSR2_IS_1)
	{
		ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static void	send_client_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	ft_putstr_fd("\e[92mSending lenght of string = ", STDOUT_FILENO);
	ft_putnbr_fd(ft_strlen(str), STDOUT_FILENO);
	ft_putstr("\n");
	send_str_len(server_pid, ft_strlen(str));
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	pa_client;

	if (argc != 3)
	{
		ft_putstr_fd("\e[33m## error - incorrect arguments! \
			 ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd("\e[31m./client <the server PID> <the \
			string to send>\n\e[0m", STDOUT_FILENO);
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
	signals_configuration_sigaction(&pa_client);
	send_client_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
