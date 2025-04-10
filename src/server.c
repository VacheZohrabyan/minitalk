/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:47:17 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:07:44 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>

void function_process(int signal)
{
    static int i;
    static char elem;

    elem |= (signal == SIGUSR1); 
    i++;
    if (i == 8)
    {
        ft_printf("%c", elem);
        elem = 0;
        i = 0;
    }
    else
        elem <<= 1;
}

int main()
{
    ft_printf("server PID = %i\n", getpid());
    signal(SIGUSR2, function_process);
    signal(SIGUSR1, function_process);

    while (1)
        pause();
}