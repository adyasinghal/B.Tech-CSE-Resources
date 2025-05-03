#include<stdio.h>

int main(){
    int arr[10] = { 12, 16, 20, 40, 50, 70 };
    int length= sizeof(arr)/sizeof(arr[0]);
    printf("%d", length);
    int n = 6;
    int key=26;
    if (n>=length){
        printf("Element can't be inserted");    
    }
    else{
        arr[n]=key;
        n=n+1;

    }
       
    for (int i = 0; i < n; i++){
       printf("%d ", arr[i]); 
    }

}