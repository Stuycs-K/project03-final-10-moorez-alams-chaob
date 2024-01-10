#include "signals.h"

static void sighandler(int signo) {
    // ctrl-c sends sigint
    if (signo == SIGINT) {
        char* exitMessage;
        sprintf(exitMessage, "Process with PID: %d Exiting due to SIGINT\n", getpid());
        printf("%s", exitMessage);
        int output = open("output.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
        write(output, exitMessage, sizeof(*exitMessage));
    }
}

int main() {

    return 0;
}