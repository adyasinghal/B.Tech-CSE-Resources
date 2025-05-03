#include<stdio.h>

int main(){
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    for (int i=0; i<rows-1; i++){
        for (int j=0; j<(rows-i)-1;j++){
            printf(" ");
        }
        for (int m=0; m<(2*i)+1;m++){
            printf("*");
        }
        printf("\n");
    }
    for (int k=0; k<(2*rows)-1; k++){
        printf("*");

    }
    for (int l=rows; l<(2*rows)-1; l++){
        for (int n=0; n<(l-i)+1;n++){
            printf(" ");
        }
        for (int p=0; p<)

    }
}