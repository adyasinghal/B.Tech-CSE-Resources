#include<stdio.h>
float compute_bmi(int n, float weight[100], float height[100], float bmi[100]){
    for(int i=1; i<=n; i++){
        float b=weight[i-1]/(height[i-1]*height[i-1]);
        bmi[i-1]=b; 
    }
    return bmi[0];
    
    
}
int main(){
    int num;
    float w, h;
    float arrh[100];
    float arrw[100];
    float bmi[100];
    
    printf("Enter the number of students in class: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        printf("Enter deatils of student %d", i);
        printf("\nEnter weight: ");
        scanf("%f", &w);
        arrw[i-1]=w;
        printf("Enter height: ");
        scanf("%f", &h);
        arrh[i-1]=h;        

    }
    float res=compute_bmi(num, arrw, arrh, bmi);
    printf("Printing BMI-value of student 1: %f", res);

}