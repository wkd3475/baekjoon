#include <stdio.h>

int main() {
    int T, k, n;
    int num[15][15];

    for (int i=0; i<15; i++) { //num[k][n]
        num[0][i] = i;
        num[i][0] = 0;
    }

    for (int i=1; i<15; i++) {
        for (int j=1; j<15; j++) {
            num[i][j] = num[i-1][j] + num[i][j-1];
        }
    }



    scanf("%d", &T);
    
    while(T-- > 0) {
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", num[k][n]);
    }
    return 0;
}