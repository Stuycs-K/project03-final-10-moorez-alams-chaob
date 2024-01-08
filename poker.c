#include "poker.h"

struct Card drawnCards[52]; // stores all cards drawn in a round, including player hands.

char* cardName(struct Card n){ // returns card name
    char* face[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    char* suit[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    char* name = malloc(strlen(face[n.face]) + strlen(" of ") + strlen(suit[n.suit]) + 1); // +1 for the null terminator
    sprintf(name, "%s of %s", face[n.face], suit[n.suit]);

    return name;
}

struct Card drawCard(){ // returns the card that it drew, adds drawn card to drawnCards array
    int slot = 0;
    int numCardsLeft = 0; // after "i" has reached 52, this number will show how many cards are left to choose from in total. it also serves as sort of a "slot" but for the cardsLeft array.
    struct Card cardsLeft[52];

    while (drawnCards[slot].id >= 0){ // set slot to the current empty slot in drawnCards to be populated
        slot++;
    }

    int i = 0;
    while (i < 52){
        int drawn = 0; // a boolean that represents that the current "i" is an id that is assumed to not be drawn (drawn set to false)

        for (int j = 0; (j < slot) && (!drawn); j++){
            if (i == drawnCards[j].id){
                drawn = 1; // if the current "i" is contained in drawnCards, then it has been drawn.
            }
        }

        if (!drawn){
            struct Card card;
            card.id = i;
            card.face = i % 13;
            card.suit = i / 13;
            cardsLeft[numCardsLeft++] = card;
        }
        i++;
    }

    drawnCards[slot] = cardsLeft[rand() % numCardsLeft];
    printf("Drew a card!: %s, ID: %d\n", cardName(drawnCards[slot]), drawnCards[slot].id);

    return drawnCards[slot];
}



void clearBoard(){ // sets drawnCards back to all empty cards.
    for (int i = 0; i < 52; i++){
        struct Card card;
        card.id = -1; // empty card
        card.face = -1; // empty card
        card.suit = -1; // empty card
        drawnCards[i] = card;
    }
}

int main(){
    srand(time(NULL));
    
    clearBoard(); // must be run before any game/round starts.

    for (int i = 0; i < 52; i++){
        drawCard();
    }

    clearBoard();
    printf("\nBoard cleared.\n\n");

    return 0;
}