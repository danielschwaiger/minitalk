/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:19 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/23 15:43:41 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "libft.h"
#include "ft_printf.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_protocol
{
	char	*message;
	int		byte;
	int		flag;
	int		data;
				
}	t_protocol;


// Define own mactros here:
#define FT_SIG_BLOCK 1
//Define functions prototipes.
void send_byte(pid_t pid, char byte, char flag);
void send_str_len(pid_t pid, int len);
void send_char(pid_t pid, char c);
void signals_configuration_sigaction(struct sigaction *pa);
// Structure to perform the communication protocol
// flag is 1 if server received the message. O if not.
// str_len total length of string to send and receive by server.
// bits sent/received.



#endif
