#ifndef  GUI_H
#define  GUI_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "text.h"

void drawButton(int x, int y, int w, int h, SDL_Renderer *renderer);
void drawText(int x, int y, const char *text, SDL_Renderer *renderer);

#endif
