#include <criterion/criterion.h>
#include <signal.h>
#include "minitalk.h"

void    tx_char(int pid, char c);

// Expose the global variable from your client's bit_tx.c
// This allows the test to "fake" the server's response
extern volatile sig_atomic_t g_ack_received; 

static int sent_signals[8];
static int signal_idx = 0;

/* ** The Linker redirects all kill() calls here.
** We use this to record what the client is doing.
*/
int __wrap_kill(pid_t pid, int sig)
{
    (void)pid;
    if (signal_idx < 8)
        sent_signals[signal_idx++] = sig;
    
    // Simulate the server's acknowledgment immediately 
    // so the client doesn't hang waiting for a real signal.
    g_ack_received = 1;
    
    return 0;
}

/*
** This test verifies that the character 'A' (ASCII 65) 
** is sent in the correct bit order.
*/
Test(client_logic, transmits_character_A)
{
    // Reset state for this test
    signal_idx = 0;
    for(int i = 0; i < 8; i++) sent_signals[i] = 0;

    // Call your actual transmission function
    // Assuming your function is named tx_char or send_char
    tx_char(1234, 'A');

    /* ** ASCII 'A' is 01000001
    ** Below is the check for MSB (Most Significant Bit) first.
    ** If your server expects LSB, you would reverse these checks.
    */
    cr_assert_eq(sent_signals[0], SIGUSR1, "Bit 7 (MSB) should be 0");
    cr_assert_eq(sent_signals[1], SIGUSR2, "Bit 6 should be 1");
    cr_assert_eq(sent_signals[2], SIGUSR1, "Bit 5 should be 0");
    cr_assert_eq(sent_signals[3], SIGUSR1, "Bit 4 should be 0");
    cr_assert_eq(sent_signals[4], SIGUSR1, "Bit 3 should be 0");
    cr_assert_eq(sent_signals[5], SIGUSR1, "Bit 2 should be 0");
    cr_assert_eq(sent_signals[6], SIGUSR1, "Bit 1 should be 0");
    cr_assert_eq(sent_signals[7], SIGUSR2, "Bit 0 (LSB) should be 1");
}