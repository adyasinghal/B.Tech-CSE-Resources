#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr=fopen("DAT4.txt","r");
    int B[10];
    int j=0;
    while ((fscanf(fptr,"%d",&B[j])) != EOF){
        j++;
    }
    fclose(fptr);

    int count=0;
    for (int k=1; k<=9; k++){
        B[k-1]=B[k];
        count++;
    }
    B[9]=0;

    for (int l=0; l<=9; l++){
        printf("%d ", B[l]);
    }
    printf("\nCOUNT= %d", count);
}