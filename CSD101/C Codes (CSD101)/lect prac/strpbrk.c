#include<stdio.h>
#include<string.h>

int main(){
    char s1[] = "SNUniv";
    char s2[] = "SNU";
    char s3[] = "NCR";
    char s4[] = "ABD";
    char* p;
    char* p1;
    char* p2;
    char* p3;
    p = strpbrk(s1, s2);
    p1 = strpbrk(s1, s3);
    p2 = strpbrk(s2, s3);
    p3 = strpbrk(s4, s3);
    /*if (p!=0 || p1!=0) {
        printf("First matching char %c\n",*p);
        printf("First matching char %c",*p1);
    }*/
    printf("First matching char %c\n",*p);
    printf("First matching char %c\n",*p1);
    printf("First matching char %c\n",*p2);
    printf("First matching char %c",*p3); //gives segmentation fault
}