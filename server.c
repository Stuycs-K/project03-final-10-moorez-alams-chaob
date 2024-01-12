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

int main(){
    struct addrinfo *hints, *results;
    hints = calloc(1, sizeof(struct addrinfo));
    char* PORT = "3444";
    
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, PORT, hints, &results);
    
    int listen_socket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    
    //this code allows the port to be freed after program exit.  (otherwise wait a few minutes)
        int yes = 1;
        if ( setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1 ) {
            printf("sockopt  error\n");
            printf("%s\n",strerror(errno));
            exit(-1);
        }

        int err = bind(listen_socket, results->ai_addr, results->ai_addrlen);
        if(err == -1){
            printf("Error binding: %s",strerror(errno));
            exit(1);
        }
        listen(listen_socket, 3);//3 clients can wait to be processed
        printf("Listening on port %s\n",PORT);

        socklen_t sock_size;
        struct sockaddr_storage client_address;
        sock_size = sizeof(client_address);

        fd_set read_fds;

        char buff[1025]="";

        while(1){

            FD_ZERO(&read_fds);
            FD_SET(STDIN_FILENO, &read_fds);
            FD_SET(listen_socket,&read_fds);
            int i = select(listen_socket+1, &read_fds, NULL, NULL, NULL);

            //if standard in, use fgets
            if (FD_ISSET(STDIN_FILENO, &read_fds)) {
                fgets(buff, sizeof(buff), stdin);
                buff[strlen(buff) - 1]= 0;
                char* args[16];
                args[0] = "cowsay";
                parse_args(buff, args);
                //execvp(args[0], args);
                printf("Recieved from terminal: '%s'\n",buff);
            }

            // if socket
            if (FD_ISSET(listen_socket, &read_fds)) {
                //accept the connection
                int client_socket = accept(listen_socket,(struct sockaddr *)&client_address, &sock_size);
                printf("Connected, waiting for data.\n");

                //read the whole buff
                read(client_socket,buff, sizeof(buff));
                //trim the string
                buff[strlen(buff)-1]=0; //clear newline
                if(buff[strlen(buff)-1]==13){
                    //clear windows line ending
                    buff[strlen(buff)-1]=0;
                }

                printf("\nRecieved from client '%s'\n",buff);
                close(client_socket);
            }
        }



        free(hints);
        freeaddrinfo(results);
        return 0;
    
    
    
}
