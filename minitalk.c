/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:22:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/24 15:00:14 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//common functions: 

//function sends len of string to server
void send_str_len(pid_t pid, int len)
{
	int shift;
	int bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (len >> shift) & 1;
		send_bite_confirmation(pid, bit, 1);
		shift--;
	}
}

// function sends one char/octet (8 bits).
// for eacg byte client sent also waits a signal back as aknowlodgement of server receiving it.
// 1 is used as a flag in our protocol to set it as sent.

void send_char(pid_t pid, char c)
{
	int shift;

	char bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		// send this bit 
		send_bite_confirmation(pid, bit, 1);
		shift--;	
	}	
}
// function send_byte sends a byte( 0 or 1) 
// return from functon will happen after aknowledgment signall in case te wait
// flat is set to !0, otherwise return.
void	send_bite_confirmation(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR1 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR2 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}



// configures signals for both sides communication.

void signals_configuration_sigaction(struct sigaction *pa)
{
	if (sigaction(SIGUSR1_IS_0, pa, NULL) < 0)
	{
		ft_putstr_fd("Error - could not send SIGUSR1", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}	
	if (sigaction(SIGUSR2_IS_1, pa, NULL) < 0)
	{
		ft_putstr_fd("Error - could not send SIGUSR2", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

