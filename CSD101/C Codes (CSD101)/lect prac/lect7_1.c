#include<stdio.h>

int main() {
int number;
// Input an integer from the user
printf("Enter an integer: ");
scanf("%d", &number);
// Print the equivalent octal and hexadecimal values
printf("Octal equivalent: %o\n", number);
printf("Hexadecimal equivalent: %X\n", number);
return 0;
}