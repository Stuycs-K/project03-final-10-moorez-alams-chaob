#include "playerData.h"

// Writes a struct containing the params to "data.txt". Does not use new lines, is NOT cross-platform compatible
void writeData (int numChips, int roundNumber, char playerInitials[]) {
    // define struct, assign values 
    int dataStructSize = sizeof(struct playerData);
    struct playerData *data = malloc(dataStructSize);
    data = malloc(dataStructSize);
    data -> numChips = numChips;
    data -> roundNumber = roundNumber;
    strncpy(data->playerInitials, playerInitials, sizeof(data->playerInitials));
    // open file, write
    FILE* w_file = fopen("data.txt", "ab");
    fwrite(data, dataStructSize, 1, w_file);
    fclose(w_file);
    free(data);
}

// Reads all structs from "data.txt" and prints them out.
void readData () {
    int dataStructSize = sizeof(struct playerData);
    FILE* r_file = fopen("data.txt", "rb");
    struct playerData *data = malloc(dataStructSize);
    while (fread(data, dataStructSize, 1, r_file) == 1) {
        printf("Name: %s\n", data -> playerInitials);
        printf("roundNumber: %d\n", data -> roundNumber);
        printf("\n");
    }
    fclose(r_file);
    free(data);
}



int main () {
    char i[2] = "ZM";
    writeData(4, 1, i);
    readData();
}