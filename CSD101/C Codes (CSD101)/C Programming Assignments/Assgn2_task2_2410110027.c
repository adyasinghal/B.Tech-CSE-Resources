#include <stdio.h> //including header file

char experience[100];

int main()
         {
            printf("Write your experience:\n ");
            fgets(experience, sizeof(experience), stdin);
            printf("My experience as a college student are as follows: %s\n", experience);
         }

