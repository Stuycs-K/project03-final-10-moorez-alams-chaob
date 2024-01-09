#include "server.h"

int err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

int main(){
    struct addrinfo *hints, *results;
    hints = calloc(1, sizeof(struct addrinfo));
    char* PORT = "9998";
    
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = AI_PASSIVE:
    getaddrinfo(NULL, PORT, hints, &results);
    
    int listen_socket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    
    
    
    
    
}
