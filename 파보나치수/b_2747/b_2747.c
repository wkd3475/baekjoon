#include <stdio.h>

int main() {
    int n;
    int pNum[50];
    scanf("%d", &n);

    for(int i=0; i<n+1; i++) {
        if(i==0) pNum[i] = 0;
        else if(i==1) pNum[i] = 1;
        else if(i==2) pNum[i] = 1;
        else {
            pNum[i] = pNum[i-2] + pNum[i-1];
        }
    }

    printf("%d", pNum[n]);
    return 0;
}