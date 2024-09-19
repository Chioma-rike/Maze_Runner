
#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHieght 24

extern SDL_Color RGB_Red; 
extern SDL_Color RGB_Green;
extern SDL_Color RGB_Blue;
extern SDL_Color RGB_White;
extern SDL_Color RGB_Yellow;

extern int worldMap[mapWidth][mapHieght];
typedef struct SDL_Instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_Instance;

void rotR(double *dirX, double *dirY, double *rotateSpeed,
double *planX, double *planY);
void rotL(double *dirX, double *dirY, double *rotateSpeed, double *planX,
double *planY);
void sdl_init_fn(SDL_Instance *); 
void handle_event(bool *quit, bool *movFor, bool *movBak,
bool *rotatRight, bool *rotatLeft);

#endif
