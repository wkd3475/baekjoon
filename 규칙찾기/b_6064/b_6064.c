#include <stdio.h>

int gcd(int a, int b) { // 유클리드 호제법
    
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t; 
    }
    
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int T, M, N, x, y;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        
        int flag = 0;
        int j = 0;
        while((x + M * j) % N != y % N) {
            if(x + M * j > lcm(M, N)) { // lcm(M, N)번째 이후 1 증가하면 <1, 1>로 처음과 같아져서 더 계산할 필요 없음
                flag = 1;
                break;
            }

            j++;
        }

        if(flag)
            printf("-1\n");
        else
            printf("%d\n", x + M * j);
    }
}