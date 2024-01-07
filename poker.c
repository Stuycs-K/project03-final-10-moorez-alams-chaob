#include "poker.h"

struct Card drawnCards[52]; // stores all cards drawn in a round, including player hands.

char* cardName(struct Card n){ // returns card name
    int id = n.id;
    char* name;
    
    char* face[13];
    char* suit[4];

    face[0], face[1], face[2], face[3], face[4], face[5], face[6], face[7], face[8], face[9], face[10], face[11], face[12] = "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King";
    suit[0], suit[1], suit[2], suit[3] = "Spades", "Hearts", "Diamonds", "Clubs";

    name = strcat(strcat(n.face, " of "), n.suit);
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
    printf(strcat(strcat("Drew a card!: ", cardName(drawnCards[slot])), "\n"));

    return drawnCards[slot];
}