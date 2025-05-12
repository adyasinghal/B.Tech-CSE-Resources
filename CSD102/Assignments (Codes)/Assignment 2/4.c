#include <stdio.h>

struct Date {
    int date;
    int month;
    int year;
};

void compare(struct Date date1, struct Date date2) {
    if(date1.year == date2.year && 
       date1.month == date2.month && 
       date1.date == date2.date) {
        printf("Equal\n");
    } else {
        printf("Unequal\n");
    }
}

int main() {

    //data for testing
    struct Date date1 = {15, 3, 2023};
    struct Date date2 = {15, 3, 2023};
    struct Date date3 = {16, 3, 2023};
    
    printf("Comparing date1 and date2: ");
    compare(date1, date2);
    
    printf("Comparing date2 and date3: ");
    compare(date1, date3);
    
    return 0;
}
