#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef PLAYERDATA_H
#define PLAYERDATA_H

struct playerData {
    int numChips;
    int roundNumber;
    char playerInitials[2];
};

void writeData (int numChips, int roundNumber, char playerInitials[]);
void readData ();

#endif