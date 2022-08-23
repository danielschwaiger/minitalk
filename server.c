/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/23 15:42:52 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// checks if server received the lenght of message.
static void receive_string_message_lenght(t_protocol *pa_server)
{
	if (pa_server->byte == sizeof(int) * 8 && pa_server->flag == 0)
	{
		pa_server->flag = 1;
		ft_putstr_fd("\e[92mreceived length = [", STDOUT_FILENO);
		ft_putnbr_fd(pa_server->data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	}
	pa_server->message[pa_server->data] = '\0';
	pa_server->byte = 0;
}


// Server handler to send and receive aknowledgemt from client and only
// after response sends the next byte to process 0 and 1 (SIGUSR1 & SIGUSR2).

static void server_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	// using our won protocol structure to make a new t_server instance?.
	static t_protocol pa_server;
	/* static int				 i; */
	
	usleep(100);
	if (pa_server.byte == 0)
		pa_server.data = 0;
	if (signal == SIGUSR1)
		pa_server.data |= 1 << (((sizeof(int) * 8) - 1) - pa_server.byte);
	else if (signal == SIGUSR2)
		pa_server.data |= 1 << (((sizeof(int) * 8) - 1) - pa_server.byte);	
	pa_server.byte++;
	receive_string_message_lenght(&pa_server);
	send_byte(info->si_pid, 0, 0);
}

int main(int argc, char **argv)
{
	(void)argv;
	struct sigaction pa_server;
	
	if (argc != 1)
	{
		ft_putstr_fd("\e[33m## error - Please run server without any arguments! ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("\e[32m## SUCCES! ##\n\e[0m", STDOUT_FILENO);
	ft_printf("\e[31m Server running (PID : %d):\n", getpid());
	sigemptyset(&pa_server.sa_mask);
	pa_server.sa_sigaction = server_handler;
	pa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	// configure sigaction signals
	signals_configuration_sigaction(&pa_server);
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

