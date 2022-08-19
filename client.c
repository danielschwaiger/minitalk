/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/19 15:58:27 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"
#include "libft.h"
#include "ft_printf.h"

// pass the norminette !! 

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

void	send_signal(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100); 
		bit++;
	}
}