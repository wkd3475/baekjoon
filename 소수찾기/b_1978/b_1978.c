#include <stdio.h>

int prime(int n) {
    if(n==1) return 0;
    else if(n==2) return 1;
    else {
        for(int i=2; i<n; i++)
            if(n % i == 0)
                return 0;
    }

    return 1;
}

int main() {
    int N, n, count=0;
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%d", &n);
        if(prime(n))
            count++;
    }

    printf("%d", count);
    return 0;
}