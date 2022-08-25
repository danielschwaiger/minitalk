/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/25 14:19:42 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	server_is_message_finished(
	t_protocol *pa_server, int *i, pid_t client_pid)
{
	if (pa_server->bits == 8 && pa_server->flag == 1)
	{
		pa_server->message[*i] = pa_server->data;
		(*i)++;
		if (pa_server->data == '\0')
		{
			ft_putstr_fd("\e[92mreceived message = [", STDOUT_FILENO);
			ft_putstr_fd(pa_server->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(pa_server->message);
			pa_server->message = NULL;
			pa_server->flag = 0;
			*i = 0;
			send_bite_confirmation(client_pid, 1, 0);
		}
		pa_server->bits = 0;
	}
}

static void	server_is_str_length_finished(t_protocol *pa_server)
{
	if (pa_server->bits == sizeof(int) * 8 && pa_server->flag == 0)
	{
		pa_server->flag = 1;
		ft_putstr_fd("\e[92mreceived length = [", STDOUT_FILENO);
		ft_putnbr_fd(pa_server->data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		pa_server->message = ft_calloc(pa_server->data + 1, sizeof(char));
		if (pa_server->message == NULL)
		{
			ft_putstr_fd("\e[31m## error - ft_calloc() ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		pa_server->message[pa_server->data] = '\0';
		pa_server->bits = 0;
	}
}

static void	server_handler(int signal, siginfo_t *info, void *context)
{
	static t_protocol	pa_server;
	static int			i;

	usleep(WAIT_100);
	(void)context;
	if (pa_server.bits == 0)
		pa_server.data = 0;
	if (signal == SIGUSR2 && pa_server.flag == 0)
		pa_server.data |= 1 << (((sizeof(int) * 8) - 1) - pa_server.bits);
	else if (signal == SIGUSR2 && pa_server.flag == 1)
		pa_server.data |= 1 << (((sizeof(char) * 8) - 1) - pa_server.bits);
	pa_server.bits++;
	server_is_str_length_finished(&pa_server);
	server_is_message_finished(&pa_server, &i, info->si_pid);
	send_bite_confirmation(info->si_pid, 0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	pa_server;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("\e[33m## error - Please run server \
			without any arguments! ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("\e[32m## SUCCES! ##\n\e[0m", STDOUT_FILENO);
	ft_printf("\e[31m Server running (PID : %d):\n", getpid());
	sigemptyset(&pa_server.sa_mask);
	pa_server.sa_sigaction = server_handler;
	pa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	signals_configuration_sigaction(&pa_server);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
