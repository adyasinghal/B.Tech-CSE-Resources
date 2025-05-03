#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define SIZE 1000000

typedef int ElementType;

void bubble_sort(ElementType aCollection[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (aCollection[j] > aCollection[j + 1]) {
                temp = aCollection[j];
                aCollection[j] = aCollection[j + 1];
                aCollection[j + 1] = temp;
            }
        }
    }
}

void selection_sort(ElementType aCollection[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (aCollection[j] < aCollection[min_idx]) {
                min_idx = j;
            }
        }
        temp = aCollection[min_idx];
        aCollection[min_idx] = aCollection[i];
        aCollection[i] = temp;
    }
}

void populate(ElementType aCollection[], int size, int start, int end) {
    assert(start < end);
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        aCollection[i] = (rand() % (end - start)) + start;
    }
}

void print_array(ElementType aCollection[], int from, int to) {
    assert(from >= 0);
    assert(from < to);
    assert(to <= SIZE);

    printf("<");
    for (int i = from; i < to; i++) {
        printf("%d; ", aCollection[i]);
    }
    printf(">\n");
}

int main() {
    ElementType myCollection[SIZE];

    populate(myCollection, SIZE, 0, 1000);

    clock_t start, end;
    double cpu_time;

    start = clock();
    bubble_sort(myCollection, SIZE);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nBubble Sort took %f seconds.\n", cpu_time);

    populate(myCollection, SIZE, 0, 1000);

    start = clock();
    selection_sort(myCollection, SIZE);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSelection Sort took %f seconds.\n", cpu_time);

    return 0;
}