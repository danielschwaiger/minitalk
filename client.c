/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/26 21:04:49 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "libft.h"
#include "ft_printf.h"

//TODO implement malloc !! 
// TODO implement a function to print-out the received string !! GNL ??? 
// pass the norminette !! 

void	send_signal(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
			//exit(1) ?
		else
			kill(pid, SIGUSR2);
			//exit(1) ?
		usleep(10000); // look how to implement it several times .. 
		bit++;
	}  // how do i know when the string ended???
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Error! Invalid number of arguments!!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || !pid || argv[2][0] == '\0')
		return (0);
	i = 0;
	while (argv[2][i])
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	send_signal('\n', pid);
	return (0);
}