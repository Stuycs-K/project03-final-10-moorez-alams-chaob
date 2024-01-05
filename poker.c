#include "poker.h"

struct Card deck[52];

struct Card drawCard(int n){
    int slot = 0;

    while (deck[slot] != NULL){
        usedCards[slot] = deck[slot];
        slot++;
    }

    for (int j = 0; j < n; j++){

    }
}

int main(){
    srand(time);
    

    return 0;
}