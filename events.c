
#include "ray_hdr.h"

void rel_ke(SDL_Event e, bool *movFor, bool *movBak,
bool *rot_l, bool *rot_r)
{
    switch (e.key.keysym.sym)
    {
        case SDLK_UP:
            *movFor = false;
            break;
        case SDLK_DOWN:
            *movBak = false;
            break;
        case SDLK_LEFT:
            *rot_l = false;
            break;
        case SDLK_RIGHT:
            *rot_r = false;
            break;
    }
}

void press_key(SDL_Event e, bool *movFor, bool *movBak,
bool *rot_l, bool *rotateRight)
{
    switch (e.key.keysym.sym)
    {
        case SDLK_UP:
            *movFor = true;
            break;
        case SDLK_DOWN:
            *movBak = true;
            break;
        case SDLK_LEFT:
            *rot_l = true;
            break;
        case SDLK_RIGHT:
            *rotateRight = true;
            break;
    }
}


void rotR(double *dirX, double *dirY, double *rotateSpeed,
double *planX, double *planY)
{
    double oldDirX = *dirX;
    *dirX = (*dirX * cos(*rotateSpeed)) - (*dirY * sin(*rotateSpeed));
    *dirY = (oldDirX * sin(*rotateSpeed)) + (*dirY * cos(*rotateSpeed));
    double oldPlaneX = *planX;
    *planX = (*planX * cos(*rotateSpeed)) - (*planY * sin(*rotateSpeed));
    *planY = (oldPlaneX * sin(*rotateSpeed)) + (*planY * cos(*rotateSpeed));
}

void rotL(double *dirX, double *dirY, double *rotateSpeed,
double *planX, double *planY)
{
    double oldDirX = *dirX;
    *dirX = (*dirX * cos(-(*rotateSpeed))) - (*dirY * sin(-(*rotateSpeed)));
    *dirY = (oldDirX * sin(-(*rotateSpeed))) + (*dirY * cos(-(*rotateSpeed)));
    double oldPlaneX = *planX;
    *planX = (*planX * cos(-(*rotateSpeed))) - (*planY * sin(-(*rotateSpeed)));
    *planY = (oldPlaneX * sin(-(*rotateSpeed))) + (*planY * cos(-(*rotateSpeed)));
}

void handle_event(bool *quit, bool *movFor, bool *movBak,
bool *rotatRight, bool *rotatLeft)
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
            *quit = true;
        if (e.type == SDL_KEYDOWN)
            press_key(e, movFor, movBak, rotatLeft, rotatRight);
        if (e.type == SDL_KEYUP)
            rel_ke(e, movFor, movBak, rotatLeft, rotatRight);
    }
}

