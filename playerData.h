#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#ifndef PLAYERDATA_H
#define PLAYERDATA_H

struct playerData {
    int numChips;
    char playerInitials[2];
};

void writeData (int numChips, char playerInitials[]);
void readData ();

#endif