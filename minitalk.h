/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:19 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/24 16:34:31 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "libft.h"
#include "ft_printf.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Structure to perform the communication protocol
// flag is 1 if server received the message. O if not.
// str_len total length of string to send and receive by server.
// bits sent/received.

typedef struct s_protocol
{
	char	*message;
	int		bits;
	int		flag;
	int		data;
				
}	t_protocol;

// Define own mactros here:
#define SIGUSR1_IS_0 SIGUSR1
#define SIGUSR2_IS_1 SIGUSR2
#define WAIT_100 100

//Define functions prototipes.
void send_bite_confirmation(pid_t pid, char byte, char flag);
void send_str_len(pid_t pid, int len);
void send_char(pid_t pid, char c);
void signals_configuration_sigaction(struct sigaction *pa);
#endif
