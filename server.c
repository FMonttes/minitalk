/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:39:28 by felipe            #+#    #+#             */
/*   Updated: 2024/01/09 13:30:44 by felipe           ###   ########.fr       */
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
		printf("%c", chr);
		chr = 0;
		bit = 0;
	}

}


int main()
{
	int	pid;

	pid = getpid();
	printf("the pid is %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, bit_to_char);
		signal(SIGUSR2, bit_to_char);
		pause();
	}
}
