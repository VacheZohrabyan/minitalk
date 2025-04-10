/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:46:54 by vzohraby          #+#    #+#             */
/*   Updated: 2025/04/10 17:43:30 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>

void process_function(int pid, unsigned char element)
{
    int i;
    unsigned char elem;
    i = 8;
    elem = element;
    while (i-- > 0)
    {
        elem = element >> i;
        if (elem % 2 == 0)
            kill(pid, SIGUSR2);
        else 
            kill(pid, SIGUSR1);
        usleep(5000);
    }
}

int main(int argc, char** argv) {
    int client_id;
    char* str;
    int i;
    
    if (argc != 3)
    {
        ft_printf("argc many argument\n");
        exit(0);
    }
    client_id = ft_atoi(argv[1]);
    str = argv[2];
    i = 0;
    while (str[i])
    {
        process_function(client_id, (unsigned char)str[i]); 
        ++i;
    }
}