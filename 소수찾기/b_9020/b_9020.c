#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {

    int *arr;
    arr = (int*)malloc((n+1) * sizeof(int));

    for(int i=0; i<n+1; i++) {
        arr[i] = i;
    }

    arr[1] = 0;

    for(int i=2; i<n+1; i++) {
        if (arr[i] == 0)
            continue;

        for (int j=i+i; j<n+1; j+=i) {
            arr[j] = 0;
        }
    }

    if(arr[n]!=0) {free(arr); return 1;}
    else {free(arr); return 0;}
}

int main() {
    int T, num, n1, n2, flag = 0;;
    scanf("%d", &T);

    while(T-->0) {
        scanf("%d", &num);
        flag = 0;
        n1 = num/2;
        n2 = num - n1;

        while(flag == 0){
            if(isPrime(n1)&&isPrime(n2)) {
                printf("%d %d\n", n1, n2);
                flag = 1;
            }
            else {n1--; n2++;}
        }
    }
}