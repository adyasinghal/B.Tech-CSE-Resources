#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_in, *fp_out;
    int arr[10000]; 
    int n = 0;
    int i, j, key;
    long long move_count = 0;

    fp_in = fopen("RAN.dat", "r");
    if (fp_in == NULL) {
        perror("Error opening input file");
        return 1;
    }

    while (fscanf(fp_in, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(fp_in);

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
            move_count++;
        }
        arr[j + 1] = key;
        move_count++;
    }

    fp_out = fopen("SELECT3.txt", "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp_out, "%d\n", arr[i]);
    }
    fclose(fp_out);

    printf("Number of element moves: %lld\n", move_count);

    return 0;
}
