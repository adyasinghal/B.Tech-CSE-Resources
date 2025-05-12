#include<stdio.h>
#include<stdlib.h>

int binsrch(int arr[], int str, int end, int x){
    int mid;
    if (str==end){
        if (arr[str]==x){
            return str;
        }
        else{
            return -1;
        }
    }
    else{
        mid=(str+end)/2;
        if (arr[mid]==x){
            return mid;
        }
        else{
            if (arr[mid]>x){
                return binsrch(arr, str, mid-1, x);
            }
            else{
                return binsrch(arr, mid+1, end, x);
            }
        }
    }
}

int main(){
    FILE *fptr=fopen("DAT5.txt","r");
    int BETA[36];
    int j=0;
    while ((fscanf(fptr,"%d",&BETA[j])) != EOF){
        j++;
    }
    fclose(fptr);

    printf("Index of 66: %d\n", binsrch(BETA, 0, 35, 66));
    printf("Number of searches for 66: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 88: %d\n", binsrch(BETA, 0, 35, 88));
    printf("Number of searches for 88: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 97: %d\n", binsrch(BETA, 0, 35, 97));
    printf("Number of searches for 97: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 34: %d\n", binsrch(BETA, 0, 35, 34));
    printf("Number of searches for 34: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 40: %d\n", binsrch(BETA, 0, 35, 40));
    printf("Number of searches for 40: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 54: %d\n", binsrch(BETA, 0, 35, 54));
    printf("Number of searches for 54: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 24: %d\n", binsrch(BETA, 0, 35, 24));
    printf("Number of searches for 24: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 99: %d\n", binsrch(BETA, 0, 35, 99));
    printf("Number of searches for 99: %d\n", binsrch(BETA, 0, 35, 66)+1);
    printf("Index of 73: %d\n", binsrch(BETA, 0, 35, 73));
    printf("Number of searches for 73: %d\n", binsrch(BETA, 0, 35, 66)+1);
}