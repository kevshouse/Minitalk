/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* server_logic.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/06 20:10:00 by kevin-ander       #+#    #+#             */
/* Updated: 2026/04/06 20:10:00 by kevin-ander      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "minitalk.h"

/*
** Pure function that can be easily tested via Criterion.
** Returns 1 if the 8-bit character is fully assembled, otherwise 0.
*/
int	process_signal_bit(int sig, int *bit_count, char *current_char)
{
	if (sig == MY_SIG_BIT1)
		*current_char |= (1 << (7 - *bit_count));
	(*bit_count)++;
	if (*bit_count == 8)
	{
		return (1);
	}
	return (0);
}