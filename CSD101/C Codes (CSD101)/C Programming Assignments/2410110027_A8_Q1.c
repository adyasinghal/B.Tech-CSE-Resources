#include<stdio.h>

void sortarr(int arr1[], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1-i;j++)
            if(arr1[j]>arr1[j+1])
            {
                int x=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=x;
            }
    

}

int findpos(int a,int arr1[],int low,int up){
    int m=(low+up)/2;
    if(arr1[m]==a)
        return m;
    if(low>up)
        return -1;
    else
    {
        if(arr1[m]<a)
            return(findpos(a,arr1,low+1,up));
        return (findpos(a,arr1,low,up-1));
    }

}

int main(){
    int n;
    int b;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    int arr1[n];
    
    for (int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
    }
    
    sortarr(arr1, n);
    /*printf("Sorted array: ");
    for (int j=0; j<=n; j++){
        printf("%d ", arr1[j]);
    }*/
    printf("Enter the number you want to search for:\n");
    scanf("%d",&b);
    int pos1= findpos(b,arr1,0,n-1);
    if(pos1==-1)
        printf("Alas! No manuscript was found at that location.\n");
    else
        printf("Success! The manuscript is hidden at index: %d\n",pos1+1);


}