#include <stdio.h>
void foo(void)
{
int a = 100;
static int b = 100;
printf("a = %d, b = %d\n", a, b);
a = a+1;
b = b+1;
}
int main(void)
{
foo();
foo();
foo();
return (0);
}