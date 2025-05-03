#include<stdio.h>

int main(){
    int arr[]= {10, 50, 30, 40, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key =50;
    int pos=-1;
    for (int i = 0; i < n; i++){ 
        if (arr[i] == key){
            pos = i;
        }
    }
    if (pos == -1) {
        printf("\nElement not found");
    }
    else{
        for(int i = pos; i < n - 1; i++){
            arr[i]=arr[i+1];

        }
        n=n-1;
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}