#include <stdlib.h>

#include "./cube.h"

struct cube {
    float edge;    
};

Cube* buildCube(float edge) {
    Cube *cube = (Cube*) malloc(sizeof(Cube));
    if (cube == NULL)
        exit(-1);

    cube->edge = edge;    

    return cube;
}

float area(Cube *cube) {
    return (cube->edge * cube->edge) * 6;
}

float volume(Cube *cube) {
    return cube->edge * cube->edge * cube->edge;
}

void destroyCube(Cube *cube) {
    free(cube);
}