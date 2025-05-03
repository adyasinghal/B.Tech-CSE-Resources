#include <stdio.h>
int main() {
int count = 0; // Initialize counter to zero
char ch; // Variable to store each character input
//ch = getchar(); // Read a character from standard input
while (ch != '\n') { // Continue looping until a newline character is encountered
count++; // Increment the character count
ch = getchar(); // Read the next character
}
printf("You entered %d characters", count); // Output the total number of characters
return 0;
}