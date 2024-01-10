#include "playerData.h"

void writeData (int numChips, int roundNumber, char playerInitials[]) {
    // define struct, assign values 
    struct playerData *data;
    int dataStructSize = sizeof(struct playerData);
    data = malloc(dataStructSize);
    data -> numChips = numChips;
    data -> roundNumber = roundNumber;
    strcpy(data -> playerInitials, playerInitials);
    // open file, write
    FILE* w_file = fopen("data.txt", "a");
    fwrite(data, dataStructSize, 1, w_file);
    fclose(w_file);
}

void readData () {
    int dataStructSize = sizeof(struct playerData);
    FILE* r_file = fopen("data.txt", "r");
    struct stat s;
    struct playerData *data;
    stat("data.txt", &s);
    // int numStructs = s.st_size / dataStructSize;
    // printf("%d", numStructs);
    fread(data, dataStructSize, 1, r_file);
    printf("%d\n", data -> numChips);
}



int main () {
    char i[2] = "ZM";
    writeData(4, 1, i);
    readData();
}