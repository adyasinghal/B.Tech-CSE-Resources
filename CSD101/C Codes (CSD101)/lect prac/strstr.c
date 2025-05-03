#include<stdio.h>
#include<string.h>

int main(){
    char str1[] = "SNUniv";
    char str2[] = "SNU";
    char str3[] = "SNZ";
    char* p;
    char* p1;
    p = strstr(str1, str2);
    p1 = strstr(str1, str3);
    printf("%s\n%s\n", p,p1);
}