/*Write a recursive function bubbleSort that takes an array and its size. It performs the
bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
they are in the wrong order.*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    if (n == 1)
        return;


    for (int i=0;i<n-1;i++) {
        if (arr[i] > arr[i+ 1]) {
            int store = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = store;
     
        }
    }

     bubbleSort(arr ,n-1);
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];                                     //int arr2[n] 
    
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}



/*for (int i = 0; i < n; i++)
    {
        arr2[n-1] = arr1[i];
    }*/