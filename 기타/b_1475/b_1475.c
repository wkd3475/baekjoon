#include <stdio.h>

int main() {
    int N, max = 0;
    int i=0;
    int num[7]; // N <= 1,000,000
    int check[10];

    for(int j = 0; j < 10; j++) {
        check[j] = 0;
    }

    scanf("%d", &N);

    if(N == 0) { //방 번호가 0이어도 1세트는 사야함
        printf("1");
        return 0;
    }

    while(N > 0) {
        num[i] = N % 10;
        N = N / 10;
        i++;
    }

    for(int j = 0; j < i; j++) {
        check[num[j]] ++;
    }

    if(check[6] < check[9]){
        while(check[9] - check[6] > 0) {
            check[9] --;
            check[6] ++;
        }
    }
    else {
        while(check[6] - check[9] > 0) {
            check[6] --;
            check[9] ++;
        }
    }

    for(int j = 0; j < 10; j++) {
        if(max < check[j])
            max = check[j];
    }

    printf("%d", max);

    return 0;
}