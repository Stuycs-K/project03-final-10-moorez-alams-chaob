#include "playerData.h"

void writeData (int numChips, int roundNumber, char playerInitials[]) {
    //define struct
    struct playerData *data;
    int dataStructSize = sizeof(struct playerData);
    data = malloc(dataStructSize);
    data -> numChips = numChips;
    strcpy(data -> playerInitials, playerInitials);
    printf("::%s\n", playerInitials);
    int w_file = open("data.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(w_file, data, dataStructSize);
}

void readData () {

}



int main () {
    char i[2] = "ZM";
    writeData(1, 1, i);
}