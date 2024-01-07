#include "poker.h"

int main(){
    srand(time(NULL));

    for (int i = 0; i < 52; i++){
        drawCard();
    }

    return 0;
}