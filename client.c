/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:35:00 by felipe            #+#    #+#             */
/*   Updated: 2024/01/09 13:31:58 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void char_to_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	pid = atoi(av[1]);

	while (av[1][i])
	{
		char_to_bit(pid, av[1][i]);
		i++;
	}
}
