#include <stdio.h>
int main()
{
int num = 25;
if (num % 2 == 0) {goto even;}
else {goto odd;}
even:
printf("%d is even", num);
return 0;
odd:
printf("%d is odd", num);
return 0;
}