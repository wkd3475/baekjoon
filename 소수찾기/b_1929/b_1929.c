#include <stdio.h>
#include <stdlib.h>

void getPrime(int min, int max) {

    int *arr;
    arr = (int*)malloc((max+1) * sizeof(int));

    for(int i=2; i<max+1; i++) {
        arr[i] = i;
    }

    for(int i=2; i<max+1; i++) {
        if (arr[i] == 0)
            continue;

        for (int j=i+i; j<max+1; j+=i) {
            arr[j] = 0;
        }
    }

    for(int i=min; i<max+1; i++) {
        if(arr[i]!=0) {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int min, max;
    scanf("%d %d", &min, &max);
    getPrime(min, max);
    return 0;
}