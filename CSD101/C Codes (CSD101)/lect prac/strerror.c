#include <stdio.h>
#include <string.h>
int main() {
printf("%s\n", strerror(0));
printf("%s\n", strerror(1));
printf("%s\n", strerror(2));
printf("%s\n", strerror(3));
return 0;
}