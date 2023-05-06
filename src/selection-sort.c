#include <stdio.h>

void populateArray(int *array, size_t size);
void writeArray(int *array, size_t size, char *message);
void selectionSort(int *elements , size_t size);

int main() {
    const int arraySize = 6;
    int elements[arraySize];
    populateArray(elements, arraySize);
    writeArray(elements, arraySize, "Before Sort");
    selectionSort(elements, arraySize);
    writeArray(elements, arraySize, "After Sort");

    return 1;
}

void populateArray(int *array, size_t size) {
    int i, value = size;
    for(i=0; i<size; i++) {
        array[i] = value--;
    }
}

void writeArray(int *array, size_t size, char *message) {    
    int i;
    printf("%s\n", message);
    printf("[");
    for (i=0; i<size; i++) {
        printf(" %i ", array[i]);        
    }    
    printf("]\n");
}

void selectionSort(int *elements , size_t size) {
    int i,j;
    for (i=0; i<size; i++) {
        //search minor element
        int positionOfTheMinorElement = i;
        for (j=(i+1); j<size; j++) {
            if (elements[j] < elements[positionOfTheMinorElement]) {
                positionOfTheMinorElement = j;
            }            
        }

        //if minor element is found, then, make the change
        if (positionOfTheMinorElement != i) {
                int help = elements[positionOfTheMinorElement];
                elements[positionOfTheMinorElement] = elements[i];
                elements[i] = help;
        }   
    }    
}