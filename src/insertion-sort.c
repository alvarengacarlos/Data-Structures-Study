#include <stdio.h>

void populateArray(int *array, int size);
void writeArray(int *array, int size, char *message);
void insertionSort(int *elements , int size);

int main() {
    const int arraySize = 4;
    int elements[4];
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
    int j, i;
    for (i=1; i<size; i++) {
      int current = elements[i];
      for (j=i; (j>0) && (current < elements[j-1]); j--) {
        elements[j] = elements[j-1];
      }
      elements[j] = current;
    }
}