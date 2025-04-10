/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:18:27 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:39:26 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_puthex(unsigned int str, int type);
int	ft_putchar(char str);
int	ft_putstr(char *str);
int	ft_putnbr(int number);
int	ft_putnbr_unsigned(unsigned int number);
int	ft_putptr(void *str);
int	ft_atoi(const char *str);

#endif 