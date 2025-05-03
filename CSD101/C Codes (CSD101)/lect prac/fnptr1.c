#include<stdio.h>

void fun1(){
    printf("fun1\n");
}
void fun2(){
    printf("fun2\n");
}
void wrapper(void(*fun)()){
    fun();
}
int main(){
    wrapper(fun1);
    wrapper(fun2);
}