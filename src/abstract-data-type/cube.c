#include <stdlib.h>

#include "./cube.h"

struct cube {
    float edge;    
};

struct cube* buildCube(float edge) {
    struct cube *cube = (struct cube*) malloc(sizeof(struct cube));
    if (cube == NULL)
        exit(1);

    cube->edge = edge;    

    return cube;
}

float area(struct cube *cube) {
    return (cube->edge * cube->edge) * 6;
}

float volume(struct cube *cube) {
    return cube->edge * cube->edge * cube->edge;
}

void destroyCube(struct cube *cube) {
    free(cube);
}