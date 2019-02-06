#include <stdio.h>
int f[1001][1001] = {0};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<n+1; i++) {
        for(int j=0; j<i+1; j++) {
            if(j==0 || j==i) f[i][j] = 1;
            else {
                f[i][j] = (f[i-1][j] + f[i-1][j-1]) % 10007;
            }
        }
    }
    printf("%d", f[n][k]);
    return 0;
}
