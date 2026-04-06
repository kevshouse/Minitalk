// client_functions.h
#ifndef CLIENT_FUNCTIONS_H
#define CLIENT_FUNCTIONS_H

void ack_handler(int sig);
void tx_bit(int server_pid, int bit);
void tx_char(int server_pid, char c);

#endif  // CLIENT_FUNCTIONS_H