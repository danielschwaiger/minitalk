/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:48 by dapanciu          #+#    #+#             */
/*   Updated: 2022/08/21 20:28:25 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("\e[33m## error - incorrect arguments! ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd("\e[31m./client <the server PID> <the string to send>\n\e[0m",STDOUT_FILENO);
		return (EXIT_FAILURE);
	}	
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[33m## error - INVALID PID ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	// sigaction implementation !
	// handler for sending sigur1 and sigur2 using t_protocol !
	return (EXIT_SUCCESS);
}

