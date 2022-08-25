/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:22:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/25 14:19:46 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signals_configuration_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1_IS_0, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup \
			 SIGUSR1 ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2_IS_1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup \
			SIGUSR2 ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	send_str_len(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bite_confirmation(pid, bit, 1);
		shift--;
	}
}

void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bite_confirmation(pid, bit, 1);
		shift--;
	}
}

void	send_bite_confirmation(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1_IS_0) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending \
				 SIGUSR1 ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2_IS_1) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending \
				SIGUSR2 ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}
