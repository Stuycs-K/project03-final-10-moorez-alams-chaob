int comboHigh(struct Card cards[5]){
    int highStrength = 0;
    for (int i = 0; i < 5; i++){
        if (cards[i].face > highStrength) highstrength = cards[i].face;
    }
    return highStrength;
}

int comboPair(struct Card cards[5]){
    
}

int comboThree(struct Card cards[5]){
    
}

int comboFour(struct Card cards[5]){
    
}

int comboStraight(struct Card cards[5]){
    
}

int comboFlush(struct Card cards[5]){
    
}

int comboFullHouse(struct Card cards[5]){
    
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
    //handStrength += combo(cards);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            int flush;
            if (card[j].suit == i) flush++;
        }
        if (flush == 5) handStrength++;
    }
    
    // full house (add 7)
    handStrength += comboFullHouse(cards);
    
}
