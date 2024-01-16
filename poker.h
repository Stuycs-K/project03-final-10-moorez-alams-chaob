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
#include <time.h>

#ifndef POKER_H
#define POKER_H

struct Card{ // 0-12 is two-ace clubs, 13-25 is two-ace diamonds, 26-38 is two-ace hearts, 39-51 is two-ace spades
    int id; // to make random draw easier
    int face;
    int suit;
};

struct Hand{
    struct Card combination[5];
    int score;
    int altScore; // used for comparing lower pair of a two pair
};

char* cardName(struct Card n);
struct Card drawCard();
void clearBoard();
void sortHand(struct Hand* hand);
void evalHand(struct Hand* hand);
void displayHand(struct Hand* hand);
void discardCards(struct Hand* hand);
void fillHand(struct Hand* hand);
int pokerGame();

#endif
