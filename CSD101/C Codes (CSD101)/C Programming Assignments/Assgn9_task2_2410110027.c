#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int findMaximum(int *arr, int size) {
    int *ptr = arr;
    int max = *ptr;  
    
    for (int i = 0; i < size; i++) {
        if (*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}

int main() {
    int size;
    printf("Enter the array size: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Input elements
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
        
    // Reverse array
    reverseArray(arr, size);
    printf("The reversed array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Maximum element
    int maximum = findMaximum(arr, size);
    printf("The maximum element within the array is: %d\n", maximum);
    
    return 0;
}