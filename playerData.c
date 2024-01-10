#include "playerData.h"

void writeData (int numChips, int roundNumber, char playerInitials[]) {
    // define struct, assign values 
    struct playerData *data;
    int dataStructSize = sizeof(struct playerData);
    data = malloc(dataStructSize);
    data -> numChips = numChips;
    strcpy(data -> playerInitials, playerInitials);
    // open file, write
    FILE* w_file = fopen("data.txt", "a");
    fwrite(data, sizeof(data), 1, w_file);
    fclose(w_file);
}

// void readData () 
// {
//     int dataStructSize = sizeof(struct playerData);
//     int r_file = open("data.txt", O_RDONLY, 0);
//     struct stat s;
//     stat("data.txt", &s)
//     int numStructs = s.st_size / dataStructSize;
//     read(w_file, data, dataStructSize);
// }



int main () {
    char i[2] = "ZM";
    writeData(1, 1, i);
}