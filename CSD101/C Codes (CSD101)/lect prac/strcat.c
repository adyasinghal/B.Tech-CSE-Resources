#include <stdio.h>
#include <string.h>
int main()
{
char s[]="Abc";
char example[100];
strcat(example, "Hello ");
strcat(example, "World!!!");
strcat(example, s);
//strcat("ab", s);
printf("%s\n", example);
return 0;
}