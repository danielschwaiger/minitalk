/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:19 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/22 11:17:05 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "libft.h"
#include "ft_printf.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Define own mactros here:
#define FT_SIG_BLOCK 1

// Structure to perform the communication protocol
// flag is 1 if server received the message. O if not.
// str_len total length of string to send and receive by server.
// bits sent/received.

typedef struct s_protocol
{
	char *message;
	int  bits;
	int  flag;
	int  str_len;
				
}	t_protocol;


#endif
