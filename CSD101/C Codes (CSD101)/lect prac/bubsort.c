#include<stdio.h>


void bubsort(int arr[], int n){
    for (int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;

            }
        }
    }
}
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubsort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}