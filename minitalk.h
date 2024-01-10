/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:23:10 by felipe            #+#    #+#             */
/*   Updated: 2024/01/10 13:23:44 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

int	check_args(const char *format, int i, va_list ap);
int	ft_atoi(const char *nptr);
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int num);
int	ft_putstr(char *str);
int	ft_putunsgnbr(unsigned int num);
int	get_lowhex(unsigned int n);
int	get_mem(unsigned long n);
int	get_upphex(unsigned int n);

#endif
