#include "signals.h"

static void sighandler(int signo, int socket) {
    // ctrl-c sends sigint
    if (signo == SIGINT) {
        // disconnect from sockert
        close(socket);
    }
}

int main() {

    return 0;
}