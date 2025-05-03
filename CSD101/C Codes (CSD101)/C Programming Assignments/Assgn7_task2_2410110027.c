#include<stdio.h>

void print_decoration(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-(i+1); j++){
            printf(" ");
        }
        for (int k=0; k<i;k++){
            printf("*~");
        } 
        printf("*");
        printf("\n");       
    }

}
int main(){
    int num;
    printf("Enter level of pattern: ");
    scanf("%d", &num);
    print_decoration(num);
}