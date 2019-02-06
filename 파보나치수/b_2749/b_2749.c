#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n;
    int *pNum = (int*)malloc(sizeof(int)*1500001);
    scanf("%lld", &n);

    n = n % 1500000; //피사노 주기;

    for(int i=0; i<n+1; i++) {
        if(i==0) pNum[i] = 0;
        else if(i==1) pNum[i] = 1;
        else if(i==2) pNum[i] = 1;
        else {
            pNum[i] = (pNum[i-2] + pNum[i-1]) % 1000000;
        }
    }

    printf("%d", pNum[n]);
    return 0;
}