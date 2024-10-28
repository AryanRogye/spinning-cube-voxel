#ifndef RENDERER_H
#define RENDERER_H 

#define WIDTH 900
#define HEIGHT 600

#include <SDL2/SDL.h>
#include <math.h>
#include "voxel.h"


int getDelta(double val, double z_val, double distance, double scale, int offset);
double getRadians(int degrees);
void RenderCube2Dto3DoldWay(Voxel* cube, SDL_Renderer *renderer, int cube_size, double x1, double y1, double z1, double x2, double y2, double z2);
void RenderCube2Dto3D(Voxel* cube, SDL_Renderer *renderer, int cube_size, double x1, double y1, double z1, double x2, double y2, double z2);
void draw_rotating_cube(SDL_Renderer *renderer, int degree);
void draw_cube(SDL_Renderer *renderer);

#endif
