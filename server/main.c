/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/04/16 12:52:28 by keanders          #+#    #+#             */
/* Updated: 2026/04/06 19:52:25 by kevin-ander      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minitalk.h" 
#include "sig_handler.h"

int main(void)
{
    struct sigaction sa;

    // Set up the signal handler
    sa.sa_sigaction = sig_handler; 
    sa.sa_flags = SA_SIGINFO | SA_NODEFER; 
    sigemptyset(&sa.sa_mask); 

    // Register the signal handlers for SIGUSR1 and SIGUSR2
    if (sigaction(MY_SIG_BIT0, &sa, NULL) < 0)
    {
        perror("sigaction failed for SIGUSR1");
        exit(EXIT_FAILURE);
    }

    if (sigaction(MY_SIG_BIT1, &sa, NULL) < 0)
    {
        perror("sigaction failed for SIGUSR2");
        exit(EXIT_FAILURE);
    }

    // Print the server's PID
    printf("Server PID: %d\n", getpid());

    // Infinite loop to keep the server running and waiting for signals
    while (1)
    {
        pause(); 
    }

    return (0); 
}