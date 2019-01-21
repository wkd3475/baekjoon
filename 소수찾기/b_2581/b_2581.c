#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sum;
    int min;
};

struct Node getPrimeSum(int min, int max) {
    struct Node p = {0, 0};

    int *arr;
    arr = (int*)malloc((max+1) * sizeof(int));

    for(int i=2; i<max+1; i++) {
        arr[i] = i;
    }

    for(int i=2; i<max+1; i++) {
        if (arr[i] == 0)
            continue;

        for (int j=i+i; j<max+1; j+=i) {
            arr[j] = 0;
        }
    }
    
    int count = 0;
    for(int i=min; i<max+1; i++) {
        p.sum += arr[i];
        if(count == 0 && arr[i] != 0) {
            p.min = arr[i];
            count ++;
        }
    }
    
    return p;
}

int main() {
    int min, max;
    scanf("%d", &min);
    scanf("%d", &max);
    
    struct Node p;
    p = getPrimeSum(min, max);
    
    if(p.sum != 0) {
        printf("%d\n%d", p.sum, p.min);
    }
    else {
        printf("-1");
    }

    return 0;
}