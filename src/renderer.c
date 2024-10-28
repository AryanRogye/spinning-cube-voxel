#include "renderer.h"

int getDelta(double val, double z_val, double distance, double scale, int offset) {
    return (int)((val * scale) / (z_val + distance) + offset);
}

double getRadians(int degrees) {
    return degrees * (M_PI / 180);
}

void RenderCube2Dto3D(Voxel* cube, SDL_Renderer *renderer, int cube_size, double x1, double y1, double z1, double x2, double y2, double z2) {
    double focal_length = 500;
    double depth = 1000;

    double offset_x = (double)WIDTH / 2;
    double offset_y = (double)HEIGHT / 2;

    int screen_x1 = ((x1 * focal_length) / (z1 + depth) + offset_x);
    int screen_y1 = ((y1 * focal_length) / (z1 + depth) + offset_y);
    int screen_x2 = ((x2 * focal_length) / (z2 + depth) + offset_x);
    int screen_y2 = ((y2 * focal_length) / (z2 + depth) + offset_y);

    SDL_RenderDrawLine(renderer, screen_x1, screen_y1, screen_x2, screen_y2);
}

void matrixMultiplication(double matrix[3][3], double points[3], double ret[3]) {
    ret[0] = matrix[0][0] * points[0] + matrix[0][1] * points[1] + matrix[0][2] * points[2];
    ret[1] = matrix[1][0] * points[0] + matrix[1][1] * points[1] + matrix[1][2] * points[2];
    ret[2] = matrix[2][0] * points[0] + matrix[2][1] * points[1] + matrix[2][2] * points[2];
}

void getCubePoints(Voxel cube[8], int i, double points[3]) {
        points[0] = cube[i].x;
        points[1] = cube[i].y;
        points[2] = cube[i].z;
}

void getRotatedValues(
    double xMatrix[3][3],
    double yMatrix[3][3],
    double zMatrix[3][3],
    double points[3],
    double final[3]
) {
        double zRot[3];
        double yRot[3];
        matrixMultiplication(zMatrix, points, zRot);   // First rotate around Z
        matrixMultiplication(yMatrix, zRot, yRot);     // Then around Y
        matrixMultiplication(xMatrix, yRot, final);    // Finally around X
}

void draw_rotating_cube(SDL_Renderer *renderer, int degree) {
    struct Voxel* cube = init_cube();
    int cube_size = 8;
    /*Voxel copy_cube[cube_size];*/

    // Get Theta
    double theta = getRadians(degree);
    
    // Calc cos and sin at the start
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    
    // X Matrix for rotation over x axis
    double xMatrix[3][3] = {{1, 0,         0         }, 
                             {0, cos_theta, -sin_theta}, 
                             {0, sin_theta, cos_theta }
    };


    // Y Matrix for rotation over y axis
    double yMatrix[3][3] = {{cos_theta  , 0 , sin_theta }, 
                            {0          , 1 , -sin_theta}, 
                            {-sin_theta , 0 , cos_theta }
    };

    
    // // Z Matrix for rotation over z axis
    double zMatrix[3][3] = {{cos_theta, -sin_theta, 0},
                             {sin_theta, cos_theta , 0},
                             {0, 0, 1},
     };

    for(int i = 0; i < cube_size; i++) {
        double points[3];
        // Get the x y and z and store into points
        getCubePoints(cube, i, points); 
        double finalVal[3];
        getRotatedValues(
            xMatrix,
            yMatrix,
            zMatrix,
            points,
            finalVal
        ); 
        for(int j= 0; j < 3; j++) {
            // Get Each Connected values x y and z
            double connected_final[3];
            getCubePoints(cube, cube[i].connected[j], points);
            getRotatedValues(xMatrix, yMatrix, zMatrix, points, connected_final);

            // Draw a line towards it
            RenderCube2Dto3D(
                cube, renderer, cube_size, 
                finalVal[0], finalVal[1], finalVal[2],
                connected_final[0], connected_final[1],connected_final[2] 
            );
        }
    }
}

void draw_cube(SDL_Renderer *renderer) {
    struct Voxel* cube = init_cube();
    int cube_size = 8;
    for(int i = 0; i < cube_size; i++) {
        int x_val = cube[i].x;
        int y_val = cube[i].y;
        int z_val = cube[i].z;
        // Each Point has 3 values which its connected to and it needs to draw a line to
        for(int j= 0; j < 3; j++) {
            int connected_x = cube[cube[i].connected[j]].x;
            int connected_y = cube[cube[i].connected[j]].y;
            int connected_z = cube[cube[i].connected[j]].z;
            RenderCube2Dto3D(cube,renderer, cube_size, x_val, y_val, z_val, connected_x, connected_y, connected_z);
        }
    }
}




