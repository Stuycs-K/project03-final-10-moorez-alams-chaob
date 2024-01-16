#include "server.h"

int err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

void parse_args(char* line, char** arg_ary){
    
    int i = 1;
    char* x;
    while(x = strsep(&line, " ")) {
        arg_ary[i] = malloc(strlen(x) + 1);
        strcpy(arg_ary[i++], x);
    }
    
    arg_ary[i] = NULL;
    
}

int main(int argc, char *argv[]){
    
    /*
    
    char* line = "telnet 149.89.161.100 3444";
    char* args[5];
    parse_args(line, args);
    execvp(args[0], args);
    
    */
    
    struct addrinfo *hints, *server;
    
    hints = calloc(1, sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, PORT, hints, &results);
    
    int client_socket = socket(server->ai_family, server_ai->socktype, server->ai_protocol);
    if (client_socket == -1){
        err();
    }
    
    
    
    
    
}
