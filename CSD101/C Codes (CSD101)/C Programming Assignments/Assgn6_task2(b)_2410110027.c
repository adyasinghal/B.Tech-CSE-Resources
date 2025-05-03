#include<stdio.h>

int main(){
    float avgscore;
    int arrgrade[100];
    int score;
    int i;
    int n;
    int sum1;

    for(i=1;i<=7;i++){
        printf("Marks for course %d " , i);
        scanf("%d", &score);
        arrgrade[i-1]=score;
    }
    printf("Enter threshold: ");
    scanf("%d",&n);
    for(int j=0; j<7;j++){
        if(arrgrade[j]<=n){
            sum1=sum1+1;
        }

    }
    printf("Number of courses for which score is less than or equal to the threshold value is: %d", sum1);


}