#include <stdio.h>

#include "array-util.h"

void populateArray(int *array, int size) {
    int value = size;
    for(int i=0; i<size; i++) {
        array[i] = value--;
    }
}

void writeArray(int *array, int size, char *message) {    
    printf("%s\n", message);
    printf("[");
    for (int i=0; i<size; i++) {
        printf(" %i ", array[i]);        
    }    
    printf("]\n");
}