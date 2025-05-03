#include <stdio.h>
int main()
        {
            char str[50];
            printf("Enter a single Word: ");
            scanf("%s\n", &str);
            printf("Entered Word is: %s", str);
            /*printf("Enter the complete sentence: ");
            scanf("%[^\n]s", &str);
            printf("\nEntered Sentence is: %s\n", str);*/
            return 0;
        }

