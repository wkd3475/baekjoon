#include <stdio.h>

int factorial(int n);

int main() {
    int n, k, result;
    scanf("%d %d", &n, &k);
    result = factorial(n) / factorial(n-k) / factorial(k);
    printf("%d", result);
    return 0;
}

int factorial(int n) {
    if(n==1 || n==0) { //factorial(0)은 1이다.
        return 1;
    }
    else {
        int result = n * factorial(n-1);
        return result;
    }
}