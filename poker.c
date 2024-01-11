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
    //printf("Drew a card!: %s, ID: %d, face: %d\n", cardName(drawnCards[slot]), drawnCards[slot].id, drawnCards[slot].face);

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

void sortHand(struct Hand* hand){ // will sort a given hand based on face values. suit values will be ignored.
    struct Card cards[5];
    memcpy(cards, hand->combination, sizeof(cards));
    int flag = 0;
    for (int i = 0; (i < 4) && (flag == 0); i++){
        flag = 1;
        for (int j = 0; j < 4-i; j++){
            if (cards[j].face > cards[j+1].face){
                flag = 0;
                struct Card temp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = temp;
            }
        }
    }
    memcpy(hand->combination, cards, sizeof(hand->combination));
}

void evalHand(struct Hand* hand){ // sets a score based on the strength of the player's hand.

    sortHand(hand);

    //0-12 high card, 13-25 pair, 26-38 two pair, altScore used for lower pair (0-12), 39-51 trips, 
    //52-61 straight (5-ace), 62-74 flush, 75-87 full house, 88-100 quads, 101-110 straight flush (royal flush is 110)

    hand->score = 1;

    //check straight flush and royal flush, maybe add just flush and just straight checks in here too?
    for (int i = 0; (i < 4) && (hand->score > 0); i++){
        int previousSuit = hand->combination[i].suit;
        int previousFace = hand->combination[i].face;
        int nextSuit = hand->combination[i+1].suit;
        int nextFace = hand->combination[i+1].face;
        if (nextSuit == previousSuit && (nextFace == previousFace + 1 || nextFace == 0 && previousFace == 12)){
            hand->score = 98 + hand->combination[4].face;
        }
        else{
            hand->score = 0;
        }
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

    struct Hand testHand;
    for (int i = 0; i < 5; i++){
        testHand.combination[i] = drawCard();
    }
    printf("Before sort: %s, %s, %s, %s, %s\n", cardName(testHand.combination[0]), cardName(testHand.combination[1]), cardName(testHand.combination[2]), cardName(testHand.combination[3]), cardName(testHand.combination[4]));
    sortHand(&testHand);
    printf("After sort: %s, %s, %s, %s, %s\n", cardName(testHand.combination[0]), cardName(testHand.combination[1]), cardName(testHand.combination[2]), cardName(testHand.combination[3]), cardName(testHand.combination[4]));

    return 0;
}