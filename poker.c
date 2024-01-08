int comboHigh(struct Card cards[5]){
    // every hand has a highest face card, iterate through to find
    int comboStrength = 0;
    for (int i = 0; i < 5; i++){ // goes through once for each card
        if (cards[i].face > comboStrength) combostrength = cards[i].face;
    }
    return comboStrength;
}

int comboPair(struct Card cards[5]){
    // for a hand to be have a pair, check each face and see if they
    // have 2 members in the hand
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int pair = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) pair++;
        }
        if (pair == 2) comboStrength += 2;
    }
}

int comboThree(struct Card cards[5]){
    // for a hand to be have three of a kind, check each face and see if they
    // have 3 members in the hand
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int three = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) three++;
        }
        if (three == 3) comboStrength += 3;
    }
}

int comboFour(struct Card cards[5]){
    // for a hand to be have four of a kind, check each face and see if they
    // have 4 members in the hand
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int four = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) four++;
        }
        if (four == 4) comboStrength += 4;
    }
}


int comboStraight(struct Card cards[5]){
    // for a hand to be a straight, every card face must be
    // within a difference of 1-4 from every other card, but
    // not 0 (to account for doubles) or greater than 4
    // assumed all hands are straights, then iterated to eliminate
    // non-straight hands
    int comboStrength = 5;
    for (int i = 0; i < 5; i++){ // goes through each card (base card)
        for (int j = 0; j < 4; j++){ // goes through each card (comparison)
            // no need to check all cards as 5th card will be checked anyway
            if (i != j){
                if (cards[i].face > cards[j].face + 4 &&
                    cards[i].face < cards[j].face - 4 &&
                    cards[i].face == cards[j].face)
                    comboStrength = 0;
            }
        }
    }
    return comboStrength;
}

int comboFlush(struct Card cards[5]){
    // for a card to be a flush, every card must be of the same suit
    // i thought of a way to optimize this function by just checking
    // if one card doesnt match the suit but i will try to implement later
    int comboStrength = 0;
    for (int i = 0; i < 4; i++){ // goes through once for each suit
        int flush = 0;
        if (card[0].suit == i)
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].suit == i) flush++;
        }
        if (flush == 5) comboStrength = 6;
    }
}

int evalHand(struct hand* playerHand){
    
    int handStrength = 0;
    struct Card cards[5] = playerHand->combination;
    
    // high (add 1)
    handStrength += comboHigh(cards);
    
    // pair (add 2)
    handStrength += comboPair(cards);
    
    // three of a kind (add 3)
    handStrength += comboThree(cards);
    
    // four of a kind (add 4)
    handStrength += comboFour(cards);
    
    // straight (add 5)
    handStrength += comboStraight(cards);

    // flush (add 6)
    handStrength += comboFlush(cards);
    
    // all the subsequent poker hands (royal flush, straight flush, etc.
    // are combinations of the previous combinations, and thus will end up
    // being greater anyway, so no reason to check for them at all
    // might adjust the strength that each combination gives to make
    // them align better with the strength of each hand in actual poker

    
}
