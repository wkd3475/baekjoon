#include <stdio.h>

int main() {
    int N, n;
    int num[1000];
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%d", &n);
        num[i] = n;
    }

    for(int i=0; i<N; i++) { //순차 정렬
        for(int j=i; j<N; j++) {
            int temp;
            if(num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for(int i=0; i<N; i++)
        printf("%d\n", num[i]);

    return 0;
}