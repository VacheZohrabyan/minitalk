/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:50:53 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:37:59 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putnbr(int n)
{
	char	num;
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	num = (nbr % 10) + '0';
	len += ft_putchar(num);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	num;
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	num = (n % 10) + '0';
	len += ft_putchar(num);
	return (len);
}
