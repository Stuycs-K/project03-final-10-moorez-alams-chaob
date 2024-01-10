#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
#include <fcntl.h>


#ifndef SIGNALS_H
#define SIGNALS_H

static void sighandler(int signo);

#endif