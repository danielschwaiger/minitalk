/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:22:52 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/22 18:59:55 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//both sides functions: 

//function sends len of string to server

void send_str_len(pid_t pid, int len)
{
	int shift;

	int byte;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		byte = (len >> shift) & 1;
		//send this byte
		send_byte(pid, byte, 1);
		shift--;
	}
}

// function sends one char/octet (8 bits).
// for eacg byte client sent also waits a signal back as aknowlodgement of server receiving it.
// 1 is used as a flag in our protocol to set it as sent.

void send_char(pid_t pid, char c)
{
	int shift;

	char byte;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		byte = (c >> shift) & 1;
		// send this byte 
		send_byte(pid, byte, 1);
		shift--;	
	}	
}
// function send_byte sends a byte( 0 or 1) 
// return from functon will happen after aknowledgment signall in case te wait
// flat is set to !0, otherwise return.

void send_byte(pid_t pid, char byte, char flag)
{
	if (byte == 0)
	{
		if (kill(pid, SIGUSR2) < 0)
			ft_putstr_fd("\e[33m## ERROR - Sending SIGUSR2 ##\n\e[0m", STDOUT_FILENO);
			exit (EXIT_FAILURE);
	}
	else if (byte == 1)
	{
		kill(pid, SIGUSR1) < 0)
			ft_putstr_fd("\e[33m## ERROR - SIGUSR1 ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
	}
	if (flag != 0)
		pause();
}
