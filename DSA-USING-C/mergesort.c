#include <stdio.h>

void merge(int array[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int leftArray[leftSize], rightArray[rightSize];
// copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
// sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
// merge the sorted halves
        merge(array, left, middle, right);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ,", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Given array is \n");
    printArray(array, arraySize);

    mergeSort(array, 0, arraySize - 1);

    printf("\nSorted array is \n");
    printArray(array, arraySize);
    return 0;
}
