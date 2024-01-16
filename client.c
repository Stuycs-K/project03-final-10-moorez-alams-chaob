#include "server.h"
#define PORT "3444"

int err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

void parse_args(char* line, char** arg_ary){
    
    int i = 1;
    char* x;
    while((x = strsep(&line, " "))) {
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
    
    struct addrinfo *hints, *results;
    
    hints = calloc(1, sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = AI_PASSIVE;
    if (getaddrinfo(NULL, PORT, hints, &results) != 0) {
        err();
    }
    
    int client_socket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    if (client_socket == -1){
        err();
    }
    
    if (connect(client_socket, results->ai_addr, results->ai_addrlen) == -1) {
        err();
    }
    
    int score;
    int f = fork();
    if (f == 0){
        char* argument_array[2];
        argument_array[0] = "./runme";
        execvp(argument_array[0], argument_array);
    }
    
    else{
        // get user input and send to server
        printf("Enter any text when you wish to start a game: ");
        char message[1024];
        fgets(message, sizeof(message), stdin);
        send(client_socket, message, strlen(message), 0);
        
        // Recieve message from server
        char buffer[1024];
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Received from server: %s\n", buffer);
        
        // Ok now close socket
        close(client_socket);
        freeaddrinfo(results);
    }

    return 0;
}
