#ifndef HW0301_H_INCLUDE
#define HW0301_H_INCLUDE

#define RED "\x1b[;31;1m"
#define BLUE "\x1b[;34;1m"
#define YELLOW "\x1b[;33;1m"
#define PURPLE "\x1b[;35;1m"
#define LG "\x1b[37;1m"
#define GREEN "\x1b[;32;1m"
#define CYAN "\x1b[;36;1;3m"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void lyric( FILE * pFile );

#endif
