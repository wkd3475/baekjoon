#include <stdio.h>

int main() {
    int N, i=0;
    int num[10];
    scanf("%d", &N);

    if(N==0) {
        printf("0");
        return 0;
    }

    while(N!=0) {
        num[i] = N % 10;
        i++;
        N /= 10;
    }

    for(int j=0; j<i; j++) {
        for(int z=j; z<i; z++) {
            if(num[j]<num[z]) {
                int temp = num[j];
                num[j] = num[z];
                num[z] = temp;
            }
        }
    }

    for(int j=0; j<i; j++) {
        printf("%d", num[j]);
    }

    return 0;
}