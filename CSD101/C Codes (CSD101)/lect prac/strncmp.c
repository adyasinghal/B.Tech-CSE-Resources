#include<stdio.h>
#include<string.h>

int main(){
    char str1[]="SNU";
    char str2[]="SNIoE";
    char str3[]="SNUniv";
    int res1=strncmp(str1,str2,3);
    int res2=strncmp(str1,str3,3);
    //int res3=strncmp(str1,str3); (this statement gives error, strncmp takes 3 arguments)
    printf("res1= %d\nres2= %d\n",res1, res2);
    //printf("res3=%d", res3);
}