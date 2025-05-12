#include <stdio.h>
#include <stdlib.h>

void selsort(int arr[], int n, int *searches, int *moves) {
    *searches = 0;
    *moves = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            (*searches)++;
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        
        if (max_idx != i) {
            int temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
            (*moves)++;
        }
    }
}

int main() {
    FILE *fptr = fopen("RAN.dat", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    int arr[20];
    int k = 0;
    while (k < 20 && fscanf(fptr, "%d", &arr[k]) == 1) {
        k++;
    }
    fclose(fptr);
    
    int searches = 0, moves = 0;
    selsort(arr, 20, &searches, &moves);
    
    // Save to SELECT1.dat
    FILE *outptr = fopen("SELECT1.dat", "w");
    if (outptr == NULL) {
        printf("Error creating output file\n");
        return 1;
    }
    
    // Print and save in descending order
    for (int l = 0; l < 20; l++) {
        printf("%d\n", arr[l]);
        fprintf(outptr, "%d\n", arr[l]);
    }
    fclose(outptr);
    
    printf("Total searches: %d\n", searches);
    printf("Total moves: %d\n", moves);
    
    return 0;
}
