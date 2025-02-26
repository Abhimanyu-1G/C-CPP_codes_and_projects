#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min ;

    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min  = j;
            }
        }


        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void  display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original \t");
     display(arr, n);
    selectionSort(arr, n);
    printf("Sorted\t");
     display(arr, n);
    return 0;
}