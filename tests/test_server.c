#include <criterion/criterion.h>
#include "minitalk.h" //

int process_signal_bit(int sig, int *bit_count, char *current_char);

Test(server_logic, processes_character_A)
{
    int bit_count = 0;
    char c = 0;
    int is_complete = 0;

    // Simulating the arrival of the binary string for 'A' (01000001)
    int signals[] = {MY_SIG_BIT0, MY_SIG_BIT1, MY_SIG_BIT0, MY_SIG_BIT0,
                     MY_SIG_BIT0, MY_SIG_BIT0, MY_SIG_BIT0, MY_SIG_BIT1};

    for (int i = 0; i < 8; i++)
	{
        is_complete = process_signal_bit(signals[i], &bit_count, &c);
        if (i < 7) {
            cr_assert_eq(is_complete, 0, "Character should not be marked complete yet");
        }
    }

    cr_assert_eq(is_complete, 1, "Character should be fully assembled");
    cr_assert_eq(c, 'A', "Character assembled incorrectly");
}

Test(logic, full_ascii_range)
{
    int     bit_count;
    char    c;

    for (int i = 1; i < 256; i++)
    {
        c = 0;
        bit_count = 0;
        for (int bit = 0; bit < 8; bit++)
        {
            // Using (7 - bit) for MSB (Most Significant Bit) first
            int sig = (i & (1 << (7 - bit))) ? SIGUSR2 : SIGUSR1; 
            
            // Call the function directly without saving to 'result'
            process_signal_bit(sig, &bit_count, &c);
        }
        cr_assert_eq(c, (char)i, "Failed at char code %d. Expected %d, got %d", i, i, (int)c);
    }
}

Test(logic, null_terminator_detection)
{
    int     bit_count = 0;
    char    c = 0;
    
    // Send 8 SIGUSR1 signals (all zeros)
    for (int i = 0; i < 8; i++)
    {
        process_signal_bit(SIGUSR1, &bit_count, &c);
    }
    cr_assert_eq(c, '\0', "8 zeros must result in a NULL terminator");
}