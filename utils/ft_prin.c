/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:29:44 by fmontes           #+#    #+#             */
/*   Updated: 2024/01/11 11:39:26 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_prin(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret += check_args(format, i, ap);
			i++;
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
