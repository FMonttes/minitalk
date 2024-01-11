/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:39:28 by felipe            #+#    #+#             */
/*   Updated: 2024/01/11 11:43:48 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int sign)
{
	static int	bit;
	static char	chr;

	if (bit < 8)
	{
		if (sign == SIGUSR1)
			chr += (1 << (7 - bit));
		bit++;
	}
	if (bit == 8)
	{
		ft_prin("\033[1;32m%c\033[0m", chr);
		chr = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_prin("\033[1;32m#    # # #    # # #####   ##   #      #    #\033[0m\n");
	ft_prin("\033[1;32m##  ## # ##   # #   #    #  #  #      #   #\033[0m\n");
	ft_prin("\033[1;32m# ## # # # #  # #   #   #    # #      ####\033[0m\n");
	ft_prin("\033[1;32m#    # # #  # # #   #   ###### #      #  #\033[0m\n");
	ft_prin("\033[1;32m#    # # #   ## #   #   #    # #      #   #\033[0m\n");
	ft_prin("\033[1;32m#    # # #    # #   #   #    # ###### #    #\033[0m\n");
	ft_prin("\n");
	ft_prin("\tthe pid is: \033[1;32m[%d]\033[0m\n", pid);
	while (1)
	{
		signal(SIGUSR1, bit_to_char);
		signal(SIGUSR2, bit_to_char);
		pause();
	}
}
