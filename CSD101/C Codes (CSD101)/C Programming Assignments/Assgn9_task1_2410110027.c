#include<stdio.h>

float addition(float *num1,float *num2){
    return *num1+*num2;
}

float subtraction(float *num1,float *num2){
    return *num1-*num2;
}

float multiplication(float *num1,float *num2){
    return *num1 * *num2;
}

float division(float *num1,float *num2){
    if (num2!=0){
        return (float) *num1/ *num2;
    }
    
}

int main(){
    float n1, n2;
    char sym;
    printf("Enter first number: ");
    scanf("%f", &n1);
    printf("Enter second number: ");
    scanf("%f", &n2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &sym);
    float (*operation)(float*, float*);
    switch(sym) {
        case '+':
            operation = addition;      
            printf("%f", operation(&n1, &n2));
            break;
        case '-':
            operation = subtraction;
            printf("%f", operation(&n1, &n2));
            break;
        case '*':
            operation = multiplication;
            printf("%f", operation(&n1, &n2));
            break;
        case '/':
            operation = division;
            printf("%f", operation(&n1, &n2));
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
            
    }
}