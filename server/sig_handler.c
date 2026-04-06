/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* sig_handler.c                                      :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/06 21:45:00 by keanders          #+#    #+#             */
/* Updated: 2026/04/06 21:45:00 by keanders         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "minitalk.h"
#include "sig_handler.h"

/* Prototype for the logic function we tested with Criterion */
int	process_signal_bit(int sig, int *bit_count, char *current_char);

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;
	static int		bit_count = 0;
	static char		c = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
		return ;
	
	/* Use the proven logic to assemble the character */
	if (process_signal_bit(sig, &bit_count, &c))
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			client_pid = 0;
		}
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
	
	/* Send acknowledgment back to client */
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}