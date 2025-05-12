#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n, int *moves) {
    *moves = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*moves)++;
        }
    }
}

int main() {
    FILE *infile = fopen("SELECT1.dat", "r");
    if (infile == NULL) {
        printf("Error: Cannot open SELECT1.dat\n");
        return 1;
    }
    
    int arr[20];
    int k = 0;
    while (k < 20 && fscanf(infile, "%d", &arr[k]) == 1) {
        k++;
    }
    fclose(infile);
    
    int moves = 0;
    selection_sort(arr, 20, &moves);
    
    FILE *outfile = fopen("SELECT2.dat", "w");
    if (outfile == NULL) {
        printf("Error: Cannot create SELECT2\n");
        return 1;
    }
    
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d\n", arr[i]);
        fprintf(outfile, "%d\n", arr[i]);
    }
    fclose(outfile);
    
    printf("\nNumber of moves: %d\n", moves);
    
    return 0;
}
