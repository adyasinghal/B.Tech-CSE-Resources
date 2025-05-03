#include <stdio.h>
#include <string.h>
int main(){
    char str[] = "CSD101 CSD102 CSD103";
    char* token = strtok(str, ",");
    while (token != NULL) {
        printf(" % s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}