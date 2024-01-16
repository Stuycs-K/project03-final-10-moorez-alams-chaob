#include "server.h"
#include "poker.h"
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
    
        
        //wait(&status);
    char username[256];
    printf("Type a username: ");
    fgets(username, sizeof(username), stdin);
    int score = pokerGame();
    //int score = 0;
    
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
        
    // get user input and send to server
    //printf("Enter any text when you wish to start a game: ");
    printf("Sending your gamescore to server...\n");
    char message[1024];
    sprintf(message, "%s %d", username, score);
    send(client_socket, message, strlen(message), 0);
        
    // Recieve message from server
    //char buffer[1024];
    //recv(client_socket, buffer, sizeof(buffer), 0);
    //printf("Received from server: %s\n", buffer);
        
    // Ok now close socket
    close(client_socket);
    freeaddrinfo(results);
    
    // checking for high score using shared memory
    int *highScore;
    int shmid = shmget(KEY, sizeof(int), 0640);
    highScore = shmat(shmid, 0, 0);
    if (score > *highScore) {
        *highScore = score;
        printf("New server-wide high score! YIPEEEEEE!!\n");
    }
    else printf("No high score just yet! Play again!\n");
    shmdt(highScore);
    

    return 0;
}
