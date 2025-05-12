#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int i, j, max_idx, temp;
    int moves = 0;
    int size = 100;
    int allRan[100];

    for(i = 0; i < size; i++) {
        allRan[i] = (rand() % 2000) + 1;
    }

    // Selection sort in descending order
    for(i = 0; i < size - 1; i++) {
        max_idx = i;
        for(j = i + 1; j < size; j++) {
            if(allRan[j] > allRan[max_idx]) {
                max_idx = j;
            }
        }        
        if(max_idx != i) {
            temp = allRan[i];
            allRan[i] = allRan[max_idx];
            allRan[max_idx] = temp;
            moves += 3;  // Counting each assignment as a move
        }
    }

    printf("Sorted array in descending order:\n");
    for(i = 0; i < size; i++) {
        printf("%d\n ", allRan[i]);
    }
    printf("\nTotal moves: %d\n", moves);

    fp = fopen("SELECT4.dat", "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for(i = 0; i < size; i++) {
        fprintf(fp, "%d\n", allRan[i]);
    }
    fclose(fp);

    return 0;
}
