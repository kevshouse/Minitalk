#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Define signal constants
#define MY_SIG_BIT0 SIGUSR1
#define MY_SIG_BIT1 SIGUSR2

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

// Function declarations for the client
void client_main(int argc, char *argv[]);
void tx_character(int server_pid, char c);
void tx_bit(int server_pid, int bit);
void acknowledgment_handler(int sig);

// Function declarations for the server
void server_main(void);
void signal_handler(int sig, siginfo_t *info, void *context);

#endif // MINITALK_H
