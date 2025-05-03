#include<stdio.h>

int main(){
    int arr[15] = { 2, 4, 1, 8, 5 };
    int n = 5;
    int x=10, pos=2;
    for (int i=n-1; i>=pos; i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=x;
    for (int i = 0; i < n+1; i++) { 
        printf("%d ", arr[i]);
    }
}