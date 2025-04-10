/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:16:09 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:37:53 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	check_format(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (format == 'x')
		return (ft_puthex(va_arg(arg, unsigned long long), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(arg, unsigned long long), 'X'));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;
	char	c;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			c = format[i + 1];
			count += check_format(c, arg);
			++i;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		++i;
	}
	va_end(arg);
	return (count);
}
