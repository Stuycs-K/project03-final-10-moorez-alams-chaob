#include "server.h"

int err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}
