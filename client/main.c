/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/04/16 12:52:28 by keanders          #+#    #+#             */
/* Updated: 2026/04/06 20:05:00 by kevin-ander      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"
#include "client_functions.h"

/* Ensure ft_atoi is declared in your minitalk.h or libft.h */

int main(int argc, char *argv[])
{
    int                 server_pid;
    struct sigaction    sa;
    int                 i;

    /* Validate command-line arguments */
    if (argc != 3)
    {
        write(2, "Usage: ./client <server_pid> <string>\n", 38);
        return (1);
    }

    /* Initialize variables after declarations */
    server_pid = ft_atoi(argv[1]);
    i = 0;

    /* Set up the acknowledgment signal handler */
    sa.sa_handler = ack_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    /* Send the string to the server */
    while (argv[2][i] != '\0')
    {
        tx_char(server_pid, argv[2][i]);
        i++;
    }
    
    /* Send the null terminator to tell the server the string is finished */
    tx_char(server_pid, '\0');

    return (0);
}