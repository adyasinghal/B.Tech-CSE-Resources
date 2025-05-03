#include<stdio.h>
#include<string.h>

int main(){
    char str1[]="SNU";
    char str2[]="SNU";
    char str3[]="ZNU";
    char str4[]="SMU";
    int res1=strcmp(str1,str2);
    int res2=strcmp(str2,str3);
    int res3=strcmp(str3,str2);
    int res4=strcmp(str2,str4);
    int res5=strcmp(str4,str3); //Returns first difference in ASCII value!
    printf("res1= %d\n res2= %d\n res3= %d\n res4= %d\n res5= %d\n", res1, res2, res3, res4, res5);
}