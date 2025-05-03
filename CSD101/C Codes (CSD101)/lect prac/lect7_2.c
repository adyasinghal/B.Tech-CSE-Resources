#include <stdio.h>
int main(void) {
int x = 10, y = 5;
y = ++x + y++;
printf("x = %d y = %d", x, y);
return 0;
}