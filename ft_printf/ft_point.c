/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:36:51 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:38:08 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_puthex(unsigned int num, int type)
{
	char	*base;
	int		len;

	len = 0;
	if (type)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		len += ft_puthex(num / 16, type);
	len += ft_putchar(base[num % 16]);
	return (len);
}

static int	convert_to_hex(unsigned long long num, int is_lower_case)
{
	int		length;
	char	*hex_base;

	if (is_lower_case)
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	length = 0;
	if (num >= 16)
		length += convert_to_hex(num / 16, is_lower_case);
	length += ft_putchar(hex_base[num % 16]);
	return (length);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	p;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (convert_to_hex(p, 1) + 2);
}
