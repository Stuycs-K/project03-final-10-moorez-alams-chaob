#include "poker.h"

struct Card drawnCards[52]; // stores all cards drawn in a round, including player hands.

char* cardName(struct Card n){ // returns card name
    char* face[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char* suit[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};

    char* name = malloc(strlen(face[n.face]) + strlen(" of ") + strlen(suit[n.suit]) + 1); // +1 for the null terminator
    sprintf(name, "%s of %s", face[n.face], suit[n.suit]);

    return name;
}

struct Card drawCard(){ // returns the card that it drew, adds drawn card to drawnCards array
    int slot = 0;
    struct Card cardsLeft[52];

    int i = 0;
    while (i < 52){
        if (i == drawnCards[slot].id){
            slot++;
        }
        else{
            struct Card card;
            card.id = i;
            card.face = i % 13;
            card.suit = i / 13;
            cardsLeft[i - slot] = card;
        }
        i++;
    }

    drawnCards[slot] = cardsLeft[rand() % (i - slot)];
    printf("Drew a card!: %s\n", cardName(drawnCards[slot]));

    return drawnCards[slot];
}

int main(){
    srand(time(NULL));
    drawCard();

    return 0;
}