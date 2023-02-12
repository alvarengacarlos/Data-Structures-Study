#include <stdio.h>

#include "./cube.h"

int main() {
    Cube *cube = buildCube(10);

    printf("Area: %.2f \n", area(cube));
    printf("Volume: %.2f \n", volume(cube));
    destroyCube(cube);

    return 0;
}