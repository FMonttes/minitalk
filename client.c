/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:35:00 by felipe            #+#    #+#             */
/*   Updated: 2024/01/10 16:40:25 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (kill(ft_atoi(av[1]), 0) == -1)
		ft_printf("\033[1;31mERROR: Wrong pid. Please try again.\033[0m\n");
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			char_to_bit(pid, av[2][i]);
			i++;
		}
		char_to_bit(pid, '\n');
		return (0);
	}
	ft_printf("\033[1;31mERROR: Too much args. Please try again.\033[0m\n");
	return (0);
}
