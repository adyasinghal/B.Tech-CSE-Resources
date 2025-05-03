#include<stdio.h>

int main() 
           {
            float phy;
            float mat;
            float che;
            float avg_marks;
            float jee;
            char snu[1];

            printf("Enter marks obtained in physics: ");
            scanf("%f" , &phy);
            printf("Enter marks obtained in maths: ");
            scanf("%f" , &mat);
            printf("Enter marks obtained in chemistry: ");
            scanf("%f" , &che);
            avg_marks=((phy+mat+che)/3);
            printf("Enter JEE percentage score: ");
            scanf("%f" , &jee);
            printf("Did udit clear SNUSAT exam? (Y/N)");
            scanf("%s" , &snu);
            printf("Your average score is: %f\n", avg_marks);
            printf("Eligibility score: %d\n" , ((avg_marks>90)&&((jee>90)||(snu=='Y'))));
            }
