#include <stdio.h>

void populateArray(int *array, size_t size);
void writeArray(int *array, size_t size, char *message);
void insertionSort(int *elements , size_t size);

int main() {
    const int arraySize = 4;
    int elements[4];
    populateArray(elements, arraySize);
    writeArray(elements, arraySize, "Before Sort");
    insertionSort(elements, arraySize);
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

void insertionSort(int *elements , size_t size) {  
    int j, i;
    for (i=1; i<size; i++) {
      int current = elements[i];
      for (j=i; (j>0) && (current < elements[j-1]); j--) {
        elements[j] = elements[j-1];
      }
      elements[j] = current;
    }
}