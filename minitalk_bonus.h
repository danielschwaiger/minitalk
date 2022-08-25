/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:19 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/25 14:19:31 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define SIGUSR1_IS_0 SIGUSR1
# define SIGUSR2_IS_1 SIGUSR2
# define WAIT_100 100
# include "libft.h"
# include "ft_printf.h"

# include <signal.h>
# include <unistd.h>

typedef struct s_protocol
{
	char	*message;
	int		bits;
	int		flag;
	int		data;				
}	t_protocol;

void	send_bite_confirmation(pid_t pid, char byte, char flag);
void	send_str_len(pid_t pid, int len);
void	send_char(pid_t pid, char c);
void	signals_configuration_sigaction(struct sigaction *pa);

#endif