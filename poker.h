#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netdb.h>

#ifndef POKER_H
#define POKER_H

struct Card{ // 0-12 is two-ace spades, 13-25 is two-ace hearts, 26-38 diamonds, 39-51 clubs
    int face;
};

struct Hand{
    struct Card combination[5];
};



#endif