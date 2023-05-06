#include <stdio.h>

void populateArray(int *array, int size);
void writeArray(int *array, int size, char *message);
void insertionSort(int *elements , int size);

int main() {
    const int arraySize = 6;
    int elements[arraySize];
    populateArray(elements, arraySize);
    writeArray(elements, arraySize, "Before Sort");
    insertionSort(elements, arraySize);
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

void insertionSort(int *elements , int size) {
    for (int i=1; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (elements[j] > elements[i]) {
                int help = elements[j];
                elements[j] = elements[i];
                elements[i] = help;
            }     
        }        
    }
}