#include<stdio.h>

int main(){
    float avgscore;
    int arrgrade[100];
    int score;
    int i;
    int n;
    float min1, max1;

    for(i=1;i<=7;i++){
        printf("Marks for course %d " , i);
        scanf("%d", &score);
        arrgrade[i-1]=score;
    }
    avgscore=(arrgrade[0]+arrgrade[1]+arrgrade[2]+arrgrade[3]+arrgrade[4]+arrgrade[5]+arrgrade[6])/7;
    min1=arrgrade[0];
    max1=arrgrade[0];
    //printf("%d", min1);
    //printf("%d", max1);

    n=sizeof(arrgrade);
    for(int j=1;j<7;j++){
        
        if (arrgrade[j] < min1) {
            min1 = arrgrade[j];
        }
        if (arrgrade[j] > max1) {
            max1 = arrgrade[j];
        }
    }
    printf("Your highest score is %f ", max1);
    printf("Your lowest score is %f ", min1);

    printf("Your average score is: %f ", avgscore);

    if (avgscore>=85){
        printf("Your grade is A");
    }
    else if(avgscore>=75 && avgscore<85){
        printf("Your grade is B");
    }
    else if(avgscore>=65 && avgscore<75){
        printf("Your grade is C");
    }
    else if(avgscore>=50 && avgscore<65){
        printf("Your grade is D");
    }
    else if(avgscore>=30 && avgscore<50){
        printf("Your grade is E");
    }
    else if(avgscore<30){
        printf("Your grade is F");
    }
}