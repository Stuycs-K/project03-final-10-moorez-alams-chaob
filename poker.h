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

struct Card{ // 0-12 is two-ace, 0-3 is spades, hearts, diamonds, clubs
    int face;
    int suit;
};

struct Hand{
    struct Card combination[5];
};



#endif