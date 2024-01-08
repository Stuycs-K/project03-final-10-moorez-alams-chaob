#include "playerData.h"

void writeData (int numChips, char playerInitials[]) {
    //define struct
    struct playerData *data;
    data = malloc(sizeof(struct playerData));
    data -> numChips = numChips;
    strcpy(data -> playerInitials, playerInitials);
    printf("::%s\n", playerInitials);
}

int main () {
    char i[2] = "ZM";
    writeData(1, i);
}