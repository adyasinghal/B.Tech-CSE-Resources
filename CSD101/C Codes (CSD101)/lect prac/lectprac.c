#include<stdio.h>

int main(){
    int arr[3][2]={{0,1},{2,3},{4,5}};
    int i;
    int j;


    for(int i=0; i<=2;i++){
        for(int j=0;j<=1;j++){
            //printf("arr[%d][%d]:%d",i,j,arr[i][j]);
            printf("%d",arr[i][j]);
        }
        printf("\n");

    }
}