#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr;
    fptr=fopen("file4.txt","w");
    fprintf(fptr, "C programming is fun\n");
    fprintf(fptr, "This is a practice question\n");
    fclose(fptr);

    fptr=fopen("file4.txt","r");
    int c;
    while((c=fgetc(fptr))!=EOF){
        printf("%c",c);
    }
    fclose(fptr);

    printf("\n");
    printf("Next method\n");

    fptr=fopen("file4.txt","r");
    char buf[100];
    while(fscanf(fptr, "%s", buf)==1){
        printf("%s", buf);
    }
    fclose(fptr);

    printf("\n");
    printf("Next method\n");

    fptr=fopen("file4.txt","r");
    char str[3];
    while(fgets(str,2,fptr)!=NULL){
        printf("%s",str);
    }
}