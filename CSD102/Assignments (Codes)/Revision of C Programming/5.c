#include<stdio.h>
#include<stdlib.h>

int linsrch(int arr[], int len1, int elem){
    
    for (int i=0; i<len1; i++){
        if (arr[i]==elem){
            return i;
        }
        
    }
    return -1;
}

int main(){
    FILE *fptr=fopen("DAT5.txt","r");
    int BETA[36];
    int j=0;
    while ((fscanf(fptr,"%d",&BETA[j])) != EOF){
        j++;
    }
    fclose(fptr);
    printf("Index of 66: %d\n", linsrch(BETA, 36, 66));
    printf("Number of searches for 66: %d\n", linsrch(BETA, 36, 66)+1);
    printf("Index of 88: %d\n", linsrch(BETA, 36, 88));
    printf("Number of searches for 88: %d\n", linsrch(BETA, 36, 88)+1);
    printf("Index of 97: %d\n", linsrch(BETA, 36, 97));
    printf("Number of searches for 97: %d\n", linsrch(BETA, 36, 97)+1);
    printf("Index of 34: %d\n", linsrch(BETA, 36, 34));
    printf("Number of searches for 34: %d\n", linsrch(BETA, 36, 34)+1);
    printf("Index of 40: %d\n", linsrch(BETA, 36, 40));
    printf("Number of searches for 40: %d\n", linsrch(BETA, 36, 40)+1);
    printf("Index of 54: %d\n", linsrch(BETA, 36, 54));
    printf("Number of searches for 54: %d\n", linsrch(BETA, 36, 54)+1);
    printf("Index of 24: %d\n", linsrch(BETA, 36, 24));
    printf("Number of searches for 24: %d\n", linsrch(BETA, 36, 24)+1);
    printf("Index of 99: %d\n", linsrch(BETA, 36, 99));
    printf("Number of searches for 99: %d\n", linsrch(BETA, 36, 99)+1);
    printf("Index of 73: %d\n", linsrch(BETA, 36, 73));
    printf("Number of searches for 73: %d\n", linsrch(BETA, 36, 73)+1);
}