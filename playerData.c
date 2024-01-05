#include "playerData.h"

void writeData (int numChips, char playerInitials[]) {
    //define struct
    struct playerData data;
    data.numChips = numChips;
    strcpy(playerInitials, data.playerInitials);
    printf("::%s\n", playerInitials);
}

int main () {
    char i[2] = "ZM";
    writeData(1, i);
}