#include <stdio.h>
#include <string.h>

int main()
{
    char ch[10]={'s', 'h', 'i', 'v', 'N', 'a', 'd', 'a', 'r', '\0'};
    char ch4[9]={'s', 'h', 'i', 'v', 'N', 'a', 'd', 'a', 'r'}; //gives error...doesn't give error when 10 is put in bracket without \0
    char ch2[9]="shivNadar"; //gives error
    char ch3[10]="shivNadar";
    
    printf("Char Array Value is: %s\n", ch);
    printf("Char Array Value is: %s\n", ch4);
    printf("String Literal Value is: %s\n", ch2);
    printf("String Literal Value is: %s\n", ch3);
}
//OUTPUT

/*Char Array Value is: shivNadar
Char Array Value is: shivNadar
String Literal Value is: shivNadar1�k
String Literal Value is: shivNadar*/