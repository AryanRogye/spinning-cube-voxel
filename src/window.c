#include "window.h"

void handleEvent(SDL_Event e, bool *keep_window_open) {
    switch (e.type)
    {
        case SDL_QUIT:
            *keep_window_open = false;
            break;
    }
}

void start_window() {
    if(SDL_Init(SDL_INIT_VIDEO)  < 0) {
        printf("Failed to initialize the SDL2 library\n");
        return;
    }
    SDL_Window *window = SDL_CreateWindow(
        "Vox Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if(!window){
        printf("Failed to make window\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Failed To Get the surface from the window");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }


    bool keep_window_open = true;
    int degree = 1;
    // Main Loop
    while(keep_window_open) {
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            handleEvent(e, &keep_window_open);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        /*draw_cube(renderer);*/
        draw_rotating_cube(renderer, degree);
        drawButton(10, 10, 100, 100, renderer);
        // Change Color to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawText(30, 20, "Hello", renderer);

        degree = (degree + 1) % 360;
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
        // For rotation
    }

    // Clean up SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
