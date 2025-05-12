#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 36
#define NUM_SUBJECTS 5

typedef struct {
    int id;
    int marks[NUM_SUBJECTS];
} Student;

void deleteAndShift(Student students[], int idToDelete, int *shiftCount) {
    int i, j;
    *shiftCount = 0;
    
    for (i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].id == idToDelete) {
            break;
        }
    }
    
    for (j = i; j < NUM_STUDENTS - 1; j++) {
        students[j] = students[j + 1];
        (*shiftCount)++;
    }
    
    // Set the last entry to ID 0 and marks as zeroes
    students[NUM_STUDENTS - 1].id = 0;
    for (i = 0; i < NUM_SUBJECTS; i++) {
        students[NUM_STUDENTS - 1].marks[i] = 0;
    }
}

int main() {
    FILE *file = fopen("DAT5.txt", "r");
    if (!file) {
        printf("Error: Could not open DAT5.txt\n");
        return 1;
    }
    
    Student students[NUM_STUDENTS];
    int shiftCount = 0;
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        fscanf(file, "%d", &students[i].id);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            students[i].marks[j] = 50; // Assuming identical marks of 50 for all subjects
        }
    }
    fclose(file);
    
    // Delete student with ID 14 and shift data
    deleteAndShift(students, 14, &shiftCount);
    
    printf("Total number of sfifts: %d\n", shiftCount);
    
    printf("Updated dataset:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("ID: %d, Marks: ", students[i].id);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
