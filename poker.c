int comboHigh(struct Card cards[5]){
    int comboStrength = 0;
    for (int i = 0; i < 5; i++){ // goes through once for each card
        if (cards[i].face > comboStrength) combostrength = cards[i].face;
    }
    return highStrength;
}

int comboPair(struct Card cards[5]){
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int pair = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) pair++;
        }
        if (pair == 2) comboStrength = 2;
    }
}

int comboThree(struct Card cards[5]){
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int three = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) three++;
        }
        if (three == 3) comboStrength = 3;
    }
}

int comboFour(struct Card cards[5]){
    int comboStrength = 0;
    for (int i = 0; i < 13; i++){ // goes through once for each face
        int four = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].face == i) four++;
        }
        if (four == 4) comboStrength = 4;
    }
}

int comboStraight(struct Card cards[5]){
    int comboStrength = 0;
    /*
    int straight;
    for (int i = 0; i < 5; i++){
        if (i == 0) cards[i].face = straight;
        else{
            if (cards[i].face == straight + 1) cards[i].face = straight;
        }
    }
     */
}

int comboFlush(struct Card cards[5]){
    int comboStrength = 0;
    for (int i = 0; i < 4; i++){ // goes through once for each suit
        int flush = 0;
        for (int j = 0; j < 5; j++){ // goes through once for each card
            if (cards[j].suit == i) flush++;
        }
        if (flush == 5) comboStrength = 6;
    }
}

int comboFullHouse(struct Card cards[5]){
    int comboStrength = 0;
    
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
    
    // full house (add 7)
    handStrength += comboFullHouse(cards);
    
}
