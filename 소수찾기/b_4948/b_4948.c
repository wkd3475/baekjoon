#include <stdio.h>
#include <stdlib.h>

int getPrime(int min) {
    int max = 2 * min;
    int count = 0;
    int *arr;
    arr = (int*)malloc((max+1) * sizeof(int));

    for(int i=0; i<max+1; i++) {
        arr[i] = i;
    }
    arr[1] = 0; //1은 소수가 아님

    for(int i=2; i<max+1; i++) {
        if (arr[i] == 0)
            continue;

        for (int j=i+i; j<max+1; j+=i) {
            arr[j] = 0;
        }
    }

    for(int i=min+1; i<max+1; i++) {
        if(arr[i]!=0) {
            count ++;
        }
    }
    return count;
}

int main() {
    int n;
    while(1) {
        scanf("%d", &n);

        if(n==0)
            break;

        printf("%d\n", getPrime(n));
    }
}