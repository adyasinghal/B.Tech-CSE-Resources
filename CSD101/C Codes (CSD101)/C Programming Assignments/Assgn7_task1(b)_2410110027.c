#include<stdio.h>

void compute_bmi(int n, float weight[100], float height[100], float bmi[100]){
    for(int i=1; i<=n; i++){
        float b=weight[i-1]/(height[i-1]*height[i-1]);
        bmi[i-1]=b; 
    }  
}

void print_bmi_details(int std_id, float weight[100], float height[100], float bmi[100]){
    printf("You would like to see the details for which student: ");
    scanf("%d", &std_id);
    printf("\nWeight: %.2f", weight[std_id-1]);
    printf("\nHeight: %.2f", height[std_id-1]);

    if (bmi[std_id-1]>=17&&bmi[std_id-1]<=18.5){
        printf("\nBMI-category: Mild Thinness");
    }
    else if(bmi[std_id-1]>18.5&&bmi[std_id-1]<=25){
        printf("\nBMI-category: Normal");
    } 
    else if(bmi[std_id-1]>25){
        printf("\nBMI-category: Overweight");
    } 
    else{
        printf("\nInhumane status");
    }
}


int main(){
    int num, std_id;
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
    compute_bmi(num, arrw, arrh, bmi);
    print_bmi_details(std_id, arrw, arrh, bmi);
}