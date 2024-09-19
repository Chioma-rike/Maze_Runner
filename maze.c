
#include "ray_hdr.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

int worldMap[mapWidth][mapHieght] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main(void)
{

    double posX = 22, posY = 14, dirX = -1, dirY = 0.4, planX = 0, planY = -0.66;
    bool quit = false;
    double oldtime = 0, time = 0;
    SDL_Instance instance;
    sdl_init_fn(&instance);
    while (!quit)
    {
        for (int x = 0; x < screenWidth; x++)
        {
            double camerax = 2 * x / (double) screenWidth - 1;
            double rayDirX = dirX + planX * camerax;
            double rayDirY = dirY + planY * camerax;
            int mapX = (int) posX, mapY = (int) posY;
            double sideDistX, sideDistY;
            double DelatX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double DeltaY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
            int stepX, stepY, side;
            double prepWallDist;
            int hit = 0;
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * DelatX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * DelatX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * DeltaY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * DeltaY;
            }
            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX += DelatX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += DeltaY;
                    mapY += stepY;
                    side = 1;
                }
                if (worldMap[mapX][mapY] > 0)
                {
                    hit = 1;
                }
            }
            if (side == 0)
            {
                prepWallDist = sideDistX - DelatX;
            }
            else
            {
                prepWallDist = sideDistY - DeltaY;
            }
            int lineHight = (int)(screenHeight / prepWallDist);
            int drawStr = -lineHight / 2 + screenHeight / 2;
            if (drawStr < 0)
            {
                drawStr = 0;
            }
            int drawStp = lineHight / 2 + screenHeight / 2;
            if (drawStp >= screenHeight)
            {
                drawStp = screenHeight - 1;
            }
            SDL_Color color;
            switch (worldMap[mapX][mapY])
            {
                case 1:
                    color = RGB_Red;
                    break;
                case 2:
                    color = RGB_Green;
                    break;
                case 3:
                    color = RGB_Blue;
                    break;
                case 4:
                    color = RGB_White;
                    break;
                default:
                    color = RGB_Yellow;
                    break;
            }
            if (side == 1)
            {
                color.r /= 2;
                color.g /= 2;
                color.b /= 2;
            }
        SDL_SetRenderDrawColor(instance.renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(instance.renderer, x, drawStr, x, drawStp); 
        }
        bool Rot_L = false, Rot_R = false, movFord = false, movBak = false;
        oldtime = time;
        time = SDL_GetTicks();
        double frametime = (time - oldtime) / 1000.0;
        double moveSpeed = frametime * 20.0;
        double rotateSpeed = frametime * 10.0;
        handle_event(&quit, &movFord, &movBak, &Rot_R, &Rot_L);
        if (movFord)
        {
            if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
                posX += dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
                posY += dirY * moveSpeed;
        }
        if (movBak)
        {
            if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
                posX -= dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
                posY -= dirY * moveSpeed;
        }
        if (Rot_R)
            rotR(&dirX, &dirY, &rotateSpeed, &planX, &planY);
        if (Rot_L)
            rotL(&dirX, &dirY, &rotateSpeed, &planX, &planY);
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderPresent(instance.renderer);
        SDL_RenderClear(instance.renderer);
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    return (0);
}

