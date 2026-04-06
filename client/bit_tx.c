/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* bit_tx.c                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/06 20:30:00 by kevin-ander       #+#    #+#             */
/* Updated: 2026/04/06 20:30:00 by kevin-ander      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

volatile sig_atomic_t g_ack_received = 0;

/* Acknowledgment signal handler */
void ack_handler(int sig)
{
    (void)sig;
    g_ack_received = 1; 
}

/* Function to send a single bit to the server */
void tx_bit(int server_pid, int bit)
{
    // CRITICAL FIX: Reset the flag BEFORE sending the signal
    g_ack_received = 0; 
    
    if (bit == 1)
    {
        kill(server_pid, MY_SIG_BIT1); 
    } 
    else
    {
        kill(server_pid, MY_SIG_BIT0); 
    }

    // Wait for acknowledgment
    while (!g_ack_received)
    {
        usleep(100); 
    }
}

/* Function to send a character to the server */
void tx_char(int server_pid, char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        tx_bit(server_pid, bit);
        i--;
    }
}