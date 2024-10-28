#ifndef WINDOW_H
#define WINDOW_H

#define WIDTH 900
#define HEIGHT 600

#include <SDL2/SDL.h>
#include "renderer.h"
#include <stdbool.h>

void start_window();
void handleEvent(SDL_Event e, bool *keep_window_open);

#endif
