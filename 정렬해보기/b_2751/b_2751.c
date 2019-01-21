#include <stdio.h>
#include <stdlib.h>

int temp[1000000];

void merge(int num[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(num[i] <= num[j]) temp[k++] = num[i++];
        else temp[k++] = num[j++];
    }

    while(i <= mid) temp[k++] = num[i++];
    while(j <= right) temp[k++] = num[j++];
    for(int a = left; a <= right; a++) num[a] = temp[a];
}

void mergeSort(int num[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        mergeSort(num, left, mid);
        mergeSort(num, mid+1, right);
        merge(num, left, mid, right);
    }
}

int main() {
    int N;
    int num[1000000];
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%d", &num[i]);
    }
    mergeSort(num, 0, N-1);

    for(int i=0; i<N; i++)
        printf("%d\n", num[i]);

    return 0;
}