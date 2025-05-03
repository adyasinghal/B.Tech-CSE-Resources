#include<stdio.h>

int main(){
    int n;
    int sum=0;
    printf("Enter a positve integer: ");
    scanf("%d", &n);
    if(n<0){
        printf("Invalid input");
    }
    
    for (int i=1; i<=n; i++){
        sum+=i;
    }
    
    printf("%d\n",sum);
}