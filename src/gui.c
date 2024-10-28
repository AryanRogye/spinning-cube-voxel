#include "gui.h"

void drawButton(int x, int y, int w, int h, SDL_Renderer *renderer) {
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
}

void drawText(int x, int y, const char *text, SDL_Renderer *renderer) {
    // Text is a string of characters get the length of the string
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++) {
        // Get font array for each character
        unsigned char *fontArray = getText(&text[i]);
        if (!fontArray) continue;
        // Draw each character
        for (int j = 0; j < FONT_HEIGHT; j++) {
            for (int k = 0; k < 5; k++) {
                if (fontArray[j] & (1 << (4 - k))) { // Check each bit from left to right
                    SDL_RenderDrawPoint(renderer, x + k + (i * 6), y + j);
                }
            }
        }
        free(fontArray);
    }
}
