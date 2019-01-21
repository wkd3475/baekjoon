#include <stdio.h>
#define MAX 500010

int main() {
    int N;
    int num[MAX];

    scanf("%d", &N);

    for(int i=0; i<N; i++)  scanf("%d", &num[i]);

    float result = 0;
    int temp[8001];

    for(int i=0; i<8001; i++) {
        temp[i] = 0;
    }

    for(int i=0; i<N; i++) {
        result += (float)num[i];
        temp[num[i]+4000] ++;
    }
    result /= N;

    int a=0;
    for(int i=0; i<8001; i++) {
        for(int j=0; j<temp[i]; j++) {
            num[a] = i - 4000;
            a++;
        } 

    }
    
    int max = 0;
    for(int i=0; i<8001; i++) {
        if(max < temp[i]) max = temp[i];
    }
    
    int count = 0;
    int b;//최빈값
    for(int i=0; i<8001; i++) {
        if(temp[i] == max) {
            b = i - 4000;
            count ++;
        }
        if(count==2) break;
    }
    
    printf("%.f\n", result);//산술평균
    printf("%d\n", num[N/2]);//N은 홀수이기 때문에 중앙값은 바로 구할 수 있음
    printf("%d\n", b);//최빈값 출력
    printf("%d\n", num[N-1]-num[0]);//범위 출력

    return 0;
}