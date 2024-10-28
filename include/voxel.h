#ifndef VOXEL_H
#define VOXEL_H

#define WIDTH 900
#define HEIGHT 600

typedef struct Voxel{
    double x;
    double y;
    double z; 
    int connected[3];
}Voxel;

Voxel* init_cube();

#endif
