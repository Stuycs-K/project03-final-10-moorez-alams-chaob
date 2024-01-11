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
    //52-61 straight (5 high-ace high), 62-74 flush, 75-87 full house, 88-100 quads, 101-110 straight flush (royal flush is 110)

    hand->score = 1;

    //check straight flush and royal flush
    for (int i = 0; (i < 4) && (hand->score > 0); i++){
        int previousSuit = hand->combination[i].suit;
        int previousFace = hand->combination[i].face;
        int nextSuit = hand->combination[i+1].suit;
        int nextFace = hand->combination[i+1].face;
        if (nextSuit == previousSuit && (nextFace == previousFace + 1)){
            hand->score = 98 + hand->combination[4].face;
            if (i == 3){
                if (hand->score == 110){
                    printf("Royal flush. Score: %d\n", hand->score);
                }
                else{
                    printf("Straight flush. Score: %d\n", hand->score);
                }
                return;
            }
        }
        else if (nextSuit == previousSuit && (nextFace == 12 && previousFace == 3 && hand->score > 1 && i == 3)){ // special case of ace-5 straight flush
            hand->score = 98 + hand->combination[3].face;
            printf("Straight flush. Score: %d\n", hand->score);
            return;
        }
        else{
            hand->score = 0;
        }
    }

    int numSame;

    //check for quads
    for (int i = 0; i < 5; i++){
        numSame = 1;
        for (int j = 0; j < 5; j++){
            if (hand->combination[i].face == hand->combination[j].face && j != i){
                numSame++;
            }
        }
        if (numSame == 4){
            hand->score = 88 + hand->combination[i].face;
            printf("Four of a kind. Score: %d\n", hand->score);
            return;
        }
    }

    //check for full house
    int hasTrips = 0;
    int hasPair = 0;
    for (int i = 0; i < 5; i++){
        numSame = 1;
        for (int j = 0; j < 5; j++){
            if (hand->combination[i].face == hand->combination[j].face && j != i){
                numSame++;
            }
        }

        if (numSame == 3){
            hasTrips = 1;
            hand->score = 75 + hand->combination[i].face;
        }
        else if (numSame == 2){
            hasPair = 1;
        }

        if (hasTrips && hasPair){
            printf("Full house. Score: %d\n", hand->score);
            return;
        }
        else{
            hand->score = 0;
        }
    }

    //check for flush
    hand->score = 1;
    for (int i = 0; (i < 4) && (hand->score > 0); i++){
        int previousSuit = hand->combination[i].suit;
        int nextSuit = hand->combination[i+1].suit;
        if (nextSuit == previousSuit){
            hand->score = 62 + hand->combination[4].face;
            if (i == 3){
                printf("Flush. Score: %d\n", hand->score);
                return;
            }
        }
        else{
            hand->score = 0;
        }
    }

    //check for straight
    hand->score = 1;
    for (int i = 0; (i < 4) && (hand->score > 0); i++){
        int previousFace = hand->combination[i].face;
        int nextFace = hand->combination[i+1].face;
        if (nextFace == previousFace + 1){
            hand->score = 49 + hand->combination[4].face;
            if (i == 3){
                printf("Straight. Score: %d\n", hand->score);
                return;
            }
        }
        else if (nextFace == 12 && previousFace == 3 && hand->score > 1 && i == 3){ // special case of ace-5 straight
            hand->score = 49 + hand->combination[3].face;
            printf("Straight. Score: %d\n", hand->score);
            return;
        }
        else{
            hand->score = 0;
        }
    }

    //check for trips
    for (int i = 0; i < 5; i++){
        numSame = 1;
        for (int j = 0; j < 5; j++){
            if (hand->combination[i].face == hand->combination[j].face && j != i){
                numSame++;
            }
        }

        if (numSame == 3){
            hand->score = 39 + hand->combination[i].face;
            printf("Three of a kind. Score: %d\n", hand->score);
            return;
        }
    }

    //check for two pair/pair
    int pairs = 0;
    int firstPairVal = 0;
    int secondPairVal = 0;
    for (int i = 0; i < 5; i++){
        numSame = 1;
        for (int j = 0; j < 5; j++){
            if (hand->combination[i].face == hand->combination[j].face && j != i){
                numSame++;
            }
        }

        if (numSame == 2 && pairs == 0){
            pairs++;
            firstPairVal = hand->combination[i].face;
        }
        else if (numSame == 2 && pairs == 1 && firstPairVal != hand->combination[i].face){
            pairs++;
            secondPairVal = hand->combination[i].face;
        }
    }

    if (pairs == 2){
        hand->score = 26 + ((firstPairVal > secondPairVal) ? firstPairVal : secondPairVal);
        hand->altScore = (firstPairVal < secondPairVal) ? firstPairVal : secondPairVal;
        printf("Two pair. Score: %d, Lower pair score: %d\n", hand->score, hand->altScore);
        return;
    }
    else if (pairs == 1){
        hand->score = 13 + ((firstPairVal > secondPairVal) ? firstPairVal : secondPairVal);
        printf("Pair. Score: %d\n", hand->score);
        return;
    }
    else{
        hand->score = hand->combination[4].face;
        printf("High card. Score: %d\n", hand->score);
        return;
    }
}

int main(){
    srand(time(NULL));
    
    clearBoard(); // must be run before any game/round starts.

    for (int i = 0; i < 52; i++){
        drawCard();
        printf("%d, ", drawnCards[i].id);
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

    struct Hand testHand2;
    struct Card card1, card2, card3, card4, card5;
    card1.face = 12, card1.suit = 0;
    card2.face = 0, card2.suit = 0;
    card3.face = 1, card3.suit = 0;
    card4.face = 2, card4.suit = 0;
    card5.face = 3, card5.suit = 0;
    testHand2.combination[0] = card1;
    testHand2.combination[1] = card2;
    testHand2.combination[2] = card3;
    testHand2.combination[3] = card4;
    testHand2.combination[4] = card5;

    evalHand(&testHand2);

    return 0;
}