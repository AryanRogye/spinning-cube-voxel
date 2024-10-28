#include "voxel.h"

Voxel* init_cube() {
    // Define cube dimensions
    double size = 100;  // Size of the cube
    
    // Just a Cube For Right now
    static Voxel cube[8];
    
    // Front face (z = -size/2)
    cube[0] = (Voxel){-size/2, -size/2, -size/2, {1, 2, 4}};  // Bottom left
    cube[1] = (Voxel){ size/2, -size/2, -size/2, {0, 3, 5}};  // Bottom Right
    cube[2] = (Voxel){-size/2,  size/2, -size/2, {0, 3, 6}};  // Top left
    cube[3] = (Voxel){ size/2,  size/2, -size/2, {1, 2, 7}};  // Top right

    // Back face (z = size/2)
    cube[4] = (Voxel){-size/2, -size/2,  size/2, {0, 5, 6}};  // Bottom left
    cube[5] = (Voxel){ size/2, -size/2,  size/2, {1, 4, 7}};  // Bottom Right
    cube[6] = (Voxel){-size/2,  size/2,  size/2, {2, 4, 7}};  // Top left
    cube[7] = (Voxel){ size/2,  size/2,  size/2, {3, 5, 6}};  // Top right 
    
    return cube;
}
