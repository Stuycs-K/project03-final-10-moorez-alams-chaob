
int evalHand(struct hand* playerHand){
    
    int handStrength;
    struct Card[5] cards = playerHand->combination;
    
    // high (add 1)
    for (int i = 0; i < 5; i++){
        handStrength += cards[i].face;
    }
    
    // pair (add 2)
    
    
    // three of a kind (add 3)
    
    
    // four of a kind (add 4)
    
    
    // straight (add 5)
    

    // flush (add 6)
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            int flush;
            if (card[j].suit == i) flush++;
        }
        if (flush == 5) handStrength++;
    }
    
    // full house (add 7)
    
}
