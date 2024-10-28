#ifndef TEXT_H
#define TEXT_H
#define FONT_HEIGHT 5

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Font data for all uppercase letters
extern const unsigned char FONT_DATA[128][FONT_HEIGHT];

unsigned char* getText(const char *text);

#endif
