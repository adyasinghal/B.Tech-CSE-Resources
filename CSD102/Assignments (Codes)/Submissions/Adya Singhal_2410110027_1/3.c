#include<stdio.h>
#include<stdlib.h>

int main(){

FILE *fptr=fopen("DAT4.txt","w");
int arr[]={12,27,30, 45, 58, 61, 75, 82, 90, 98};
for (int i=0; i<=9; i++){
    fprintf(fptr, "%d\n", arr[i]);
}
fclose(fptr);

fptr=fopen("DAT4.txt","r");

int A[10];
int j=0;
while ((fscanf(fptr,"%d",&A[j])) != EOF){
    j++;
}
fclose(fptr);

printf("Printing array in stored order: ");
for (int k=0; k<=9; k++){
    printf("%d ", A[k]);
}
printf("\n");

printf("Printing array in reverse order: ");
for (int l=9; l>=0; l--){
    printf("%d ", A[l]);
}
}
