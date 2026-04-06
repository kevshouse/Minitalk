#ifndef SIG_HANDLER_H
#define SIG_HANDLER_H

#include <signal.h>
#include <sys/types.h>

// Signal handler function prototype
void sig_handler(int sig, siginfo_t *info, void *context);

#endif // SIG_HANDLER_H
