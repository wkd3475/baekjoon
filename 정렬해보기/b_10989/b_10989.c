#include <stdio.h>

int main() {
    int N, n;
    int num[10001];
    scanf("%d", &N);

    for(int i=0; i<10001; i++) num[i] = 0;

    for(int i=0; i<N; i++) {
        scanf("%d", &n);
        
        num[n] ++;
    }

    for(int i=1; i<10001; i++) {
        for(int j=0; j<num[i]; j++) printf("%d\n", i);
    }

    return 0;
}