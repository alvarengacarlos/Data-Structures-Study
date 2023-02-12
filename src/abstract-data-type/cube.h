typedef struct cube Cube;

Cube* buildCube(float edge);
float area(Cube *cube);
float volume(Cube *cube);
void destroyCube(Cube *cube);