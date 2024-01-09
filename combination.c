#include "poker.h"

struct Hand sortHand(struct Hand hand){ // will return a sorted version of a given hand based on face value. suit values will be ignored.

}

int evalHand(struct Hand hand){ // returns a score based on the strength of the player's hand.
    //check from best to worst, so the best hand met will end the evaluation

    //***SORT HAND HERE***// struct Hand sortedHand = sortHand();
    
    int score = 1; //equal to highest face if high card, 20 if pair, 30 if two pair, 40 if trips, 
                   //50 if straight, 60 if flush, 70 if full house, 80 if quads, 90 if straight flush, 
                   //100 if royal flush. these values don't have significance other than being used for comparison.
    
    struct Card cards[5] = hand.combination; // ***SHOULD SAY sortedHand.combination;
    
    //royal flush, straight flush, four of a kind, full house, flush, straight, three of a kind, two pair, pair, high card
    
    //check straight flush and royal flush, maybe add just flush and just straight checks in here too? 
    for (int i = 0; (i < 4) && (score > 0); i++){
        previousSuit = cards[i].suit;
        previousFace = cards[i].face;
        nextSuit = cards[i+1].suit;
        nextFace = cards[i+1].face;
        if (nextSuit == previousSuit && (nextFace == previousFace + 1 || nextFace == 0 && previousFace == 12)){
            score = 90;
            if (i == 3){
                if (cards[i+1].face = 12){
                    score = 100;
                }
                return score;
            }
        }
        else{
            score = 0;
        }
    }
}