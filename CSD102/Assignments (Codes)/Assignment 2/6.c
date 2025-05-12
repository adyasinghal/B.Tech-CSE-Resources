#include <stdio.h>

int seriesSum(int m, int n) {
    if(m > n) return 0;
    return (m * m) + seriesSum(m + 1, n);
}

int main() {
    int m = 2, n = 6;
    int result = seriesSum(m, n);
    printf("Sum of series from %d to %d is: %d\n", m, n, result);
}
