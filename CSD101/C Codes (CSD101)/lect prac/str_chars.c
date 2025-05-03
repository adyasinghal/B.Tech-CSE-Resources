#include<stdio.h>

int main(){
    //char txt[] = "We are the so-called "Vikings" from the north."; (gives error)
    char txt1[]= "We are the so-called \"Vikings\" from the north.";
    char txt2[] = "It\'s alright.";
    char txt3[] = "The character \\ is called backslash.";
    //printf("%s\n", txt);
    printf("%s\n", txt1);
    printf("%s\n", txt2);
    printf("%s\n", txt3);
}

/*
OUTPUT:

We are the so-called "Vikings" from the north.
It's alright.
The character \ is called backslash.

*/