#include "poker.h"

void sortHand(struct Hand hand){ // will return a sorted version of a given hand based on face value. suit values will be ignored.
    struct Card cards[5] = hand.combination;
    int flag = 0;
    for (int i = 0; i < 5 && flag == 0; i++){
        flag = 1;
        for (int j = 1; j < 5; j++){
            if (cards[j-1].face > cards[j].face){
                flag = 0;
                struct Card temp = cards[j-1];
                cards[j-1] = cards[j];
                cards[j] = temp;
            }
        }
    }
    hand.combination = cards[5];
}

void evalHand(struct Hand hand){ // returns a score based on the strength of the player's hand.
    //check from best to worst, so the best hand met will end the evaluation

    sortHand(hand);

    struct Card cards[5] = hand.combination; // ***SHOULD SAY sortedHand.combination;
    //0-12 high card, 13-25 pair, 26-38 two pair, altScore used for lower pair (0-12), 
    //royal flush, straight flush, four of a kind, full house, flush, straight, three of a kind, two pair, pair, high card
    
    //check straight flush and royal flush, maybe add just flush and just straight checks in here too?
    for (int i = 0; (i < 4) && (score > 0); i++){
        int previousSuit = cards[i].suit;
        int previousFace = cards[i].face;
        int nextSuit = cards[i+1].suit;
        int nextFace = cards[i+1].face;
        if (nextSuit == previousSuit && (nextFace == previousFace + 1 || nextFace == 0 && previousFace == 12)){
            hand.score = ;
            if (i == 3){
                if (nextFace = 12){
                    hand.score = 10;
                }
            }
        }
        else{
            hand.score = 0;
        }
    }
}