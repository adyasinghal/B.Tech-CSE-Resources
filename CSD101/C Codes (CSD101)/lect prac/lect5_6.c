#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter a number in decimal form: ");
    scanf("%d", &a);
    printf("Enter a number in octal form: ");
    scanf("%i", &b);
    printf("Enter a number in hexadecimal form: ");
    scanf("%i", &c);

    printf("a = %i, b = %i, c = %i", a, b, c);    

}