#include<stdio.h>

int main()
        {
            int ascii_value;
            char ch;
            printf("Enter a character: ");
            scanf("%c", &ch);
            ascii_value= (int)ch;
            printf("The ascii value of %c is %d\n" , ch, ascii_value);
        }