#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int code;
    char name[50];
    struct Date joinDate;
};

int calculateYears(struct Date join, struct Date current) {
    int years = current.year - join.year;
    if(current.month < join.month || 
      (current.month == join.month && current.day < join.day)) {
        years--;
    }
    return years;
}

void checkTenure(struct Employee employees[], int n, struct Date currentDate) {
    for(int i = 0; i < n; i++) {
        if(calculateYears(employees[i].joinDate, currentDate) >= 3) {
            printf("Employee: %s\n", employees[i].name);
        }
    }
}
int main() {
    struct Employee employees[3];
    struct Date currentDate = {2, 2, 2025};  // Current date
    
    //data for testing
    employees[0] = (struct Employee){1, "A", {1, 1, 2020}};
    employees[1] = (struct Employee){2, "B", {15, 3, 2023}};
    employees[2] = (struct Employee){3, "C", {10, 1, 2021}};
    
    printf("Employees with 3+ years of tenure:\n");
    checkTenure(employees, 3, currentDate);
    
    return 0;
}
