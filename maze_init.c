
#include "ray_hdr.h"


void sdl_init_fn(SDL_Instance *instance)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error in Initlizing the SDL %s\n", SDL_GetError());
        return;
    }
    instance->window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            screenWidth, screenHeight, 0);
    if (instance->window == NULL)
    {
        printf("Error in inilizing Window %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }
    instance->renderer = SDL_CreateRenderer(instance->window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (instance->renderer == NULL)
    {
        SDL_DestroyWindow(instance->window);
        printf("Error in rendereing the image %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }
}
