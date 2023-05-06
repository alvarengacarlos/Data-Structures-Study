#include <stdio.h>

void populateArray(int *array, int size);
void writeArray(int *array, int size, char *message);
void selectionSort(int *elements , int size);

int main() {
    const int arraySize = 6;
    int elements[arraySize];
    populateArray(elements, arraySize);
    writeArray(elements, arraySize, "Before Sort");
    selectionSort(elements, arraySize);
    writeArray(elements, arraySize, "After Sort");

    return 1;
}

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

void selectionSort(int *elements , int size) {
    for (int i=0; i<size; i++) {
        int positionOfTheMinorElement = i;
        for (int j=(i+1); j<size; j++) {
            if (elements[j] < elements[i]) {
                positionOfTheMinorElement = j;
            }            
        }
        if (positionOfTheMinorElement != i) {
                int help = elements[positionOfTheMinorElement];
                elements[positionOfTheMinorElement] = elements[i];
                elements[i] = help;
        }   
    }    
}