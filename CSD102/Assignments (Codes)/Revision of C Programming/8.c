#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 36
#define NUM_SUBJECTS 5

typedef struct {
    int id;
    int marks[NUM_SUBJECTS];
} Student;

int insertAndShift(Student students[], int newID, int *shiftCount) {
    int i, j;
    *shiftCount = 0;
    
    // Find the position to insert the new student
    for (i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].id == 0 || students[i].id > newID) {
            break;
        }
    }
    
    // Shift elements to the right to make space for the new student
    for (j = NUM_STUDENTS - 1; j > i; j--) {
        students[j] = students[j - 1];
        (*shiftCount)++;
    }
    
    // Insert the new student
    students[i].id = newID;
    for (j = 0; j < NUM_SUBJECTS; j++) {
        students[i].marks[j] = 50; // Assuming identical marks of 50 for all subjects
    }
    
    return *shiftCount;
}

int main() {
    Student students[NUM_STUDENTS];
    int shiftCount = 0;

    
    // Insert a new student with ID 20
    insertAndShift(students, 20, &shiftCount);
    
    // Print total number of shifts
    printf("Total number of data movements (shifts): %d\n", shiftCount);
    
    // Optional: Print updated dataset
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
