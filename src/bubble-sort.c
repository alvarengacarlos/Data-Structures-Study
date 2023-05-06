#include <stdio.h>

void populateArray(int *array, size_t size);
void writeArray(int *array, size_t size, char *message);
void bubbleSort(int *elements, size_t size);

int main() {    
    const int arraySize = 6;
    int elements[arraySize];

    populateArray(elements, arraySize);
    writeArray(elements, arraySize, "Before sort");
    bubbleSort(elements, arraySize);
    writeArray(elements, arraySize, "After sort");
    
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

void bubbleSort(int *elements, size_t size) {
    int i, previous;
    do {
        previous = 0;
        for (i=0; i<(size-1); i++) {
            if (elements[i] > elements[i+1]) {
                int help = elements[i];            
                elements[i] = elements[i+1];            
                elements[i+1] = help;
                previous = i;
            }
        }
        size--;
    } while(previous != 0);
}