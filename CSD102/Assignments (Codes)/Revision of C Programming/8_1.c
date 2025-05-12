#include <stdio.h>
#include <stdlib.h>

#define Mark1 20
#define Mark2 23
#define Mark3 24
#define Mark4 19
#define Mark5 33

typedef struct Student_Data{
    int ID;
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
}Studata;

int Beta[36];


int Findindex(Studata arr[],int l,int r, int loc){
    int mid=(l+r)/2;
    if (l<= r){
        if (arr[mid].ID==loc){
            return mid;
        }
        else if (arr[mid].ID>loc){
            return Findindex(arr,l,mid-1,loc);
        }
        else{
            return Findindex(arr,mid+1,r,loc);
        }
        
    }
    return -1;
}


void Deletedata(Studata arr[],int arrsize,int data){
    int index=Findindex(arr,0,35,data);
    if (index==-1){
        printf("The given ID doesn't exist");
    }
    else{
        int cnt=0;
        for (int i=index;i<arrsize-1;i++){
            arr[i]=arr[i+1];
            cnt++;
        }
        arr[arrsize-1]=(Studata){0,0,0,0,0,0,};
        printf("Data successfully deleted\n");
        printf("Total Number of Movements:%d",cnt);
    }
}


void InsertData(Studata new_Student,Studata arr[],int size_of_array){
    
    if (new_Student.ID<(arr)[size_of_array-1].ID){
        int a;
        for (int i=new_Student.ID;i<(arr)[size_of_array-1].ID;i++){
            a=Findindex(arr,0,size_of_array,i);
            if (a!=-1){
                break;
            }
        }
        for (int i=size_of_array;i>a;i--){
            (arr)[i]=(arr)[i-1];
        }
        (arr)[a]=new_Student;
    }
    else{
        (arr)[size_of_array]=new_Student;
    }
    printf("\nOperation Successful");
}


int main(){

    FILE *fptr;
    fptr=fopen("DAT5.txt","r");
    
    int BETA[36];
    for (int i=0;i<36;i++){
        fscanf(fptr, "%d",&BETA[i]);
    }
    fclose(fptr);

    Studata arr[36];

    for(int i=0;i<36;i++){
        arr[i]=(Studata){BETA[i],Mark1,Mark2,Mark3,Mark4,Mark5};
    }
    Deletedata(arr,36,14);
    InsertData((Studata){20,Mark1,Mark2,Mark3,Mark4,Mark5},arr,35);
    
}