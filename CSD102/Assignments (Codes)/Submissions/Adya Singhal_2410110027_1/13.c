#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n, int *moves) {
    int i, j, min_idx, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*moves)++;
        }
    }
}

int main() {
    int arr[1000], n = 0, i, j, moves = 0;
    FILE *input, *output;
    
    // Load data from SELECT4
    input = fopen("SELECT4.dat", "r");
    if (input == NULL) {
        printf("Error opening SELECT4 file\n");
        return 1;
    }
    
    while (fscanf(input, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(input);
    
    // Check for duplicates and subtract 1 from one of the duplicates
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                arr[j]--;
            }
        }
    }
    
    // Sort the array using Selection Sort
    selectionSort(arr, n, &moves);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d\n ", arr[i]);
    }
    printf("\n");
    
    printf("Number of moves: %d\n", moves);
    
    // Save the elements to SELECT2
    output = fopen("SELECT2.txt", "w");
    if (output == NULL) {
        printf("Error opening SELECT2 file\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        fprintf(output, "%d\n", arr[i]);
    }
    fclose(output);
    
    return 0;
}


