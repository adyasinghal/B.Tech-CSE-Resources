#include <stdio.h>
#include <string.h>

struct Student {
    int roll_number;
    char name[50];
    char department[50];
    char course[30];
    int year_of_joining;
};

void print_students_by_year(struct Student students[], int total_students, int year) {
    int found = 0;
    printf("\nStudents who joined in %d:\n", year);
    
    for (int i = 0; i < total_students; i++) {
        if (students[i].year_of_joining == year) {
            printf("%s\n", students[i].name);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found for year %d\n", year);
    }
}

void print_student_details(struct Student students[], int total_students, int roll) {
    int found = 0;
    
    for (int i = 0; i < total_students; i++) {
        if (students[i].roll_number == roll) {
            printf("\nStudent Details:\n");
            printf("Roll Number: %d\n", students[i].roll_number);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].year_of_joining);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent with roll number %d not found\n", roll);
    }
}

int main() {
    struct Student students[450];  // Array to store up to 450 students
    int total_students = 0;
    
    // Adding some test data
    students[total_students].roll_number = 101;
    strcpy(students[total_students].name, "Rahul Kumar");
    strcpy(students[total_students].department, "Computer Science");
    strcpy(students[total_students].course, "B.Tech");
    students[total_students].year_of_joining = 2022;
    total_students++;
        
    students[total_students].roll_number = 103;
    strcpy(students[total_students].name, "Amit Singh");
    strcpy(students[total_students].department, "Mechanical");
    strcpy(students[total_students].course, "B.Tech");
    students[total_students].year_of_joining = 2023;
    total_students++;
    
    // Testing the functions
    printf("Testing search by year:\n");
    print_students_by_year(students, total_students, 2022);
    print_students_by_year(students, total_students, 2023);
    
    printf("\nTesting search by roll number:");
    print_student_details(students, total_students, 103);
    print_student_details(students, total_students, 105);  //non-existent roll number
    
    return 0;
}
