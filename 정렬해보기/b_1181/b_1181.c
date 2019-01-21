#include <stdio.h>
#include <string.h>

char temp[20000][51];

void merge(char s[][51], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(strlen(s[i])>strlen(s[j])||(strlen(s[i])==strlen(s[j])&&strcmp(s[i],s[j])>0)) strcpy(temp[k++], s[j++]);
        else strcpy(temp[k++], s[i++]);
    }

    while(i <= mid) strcpy(temp[k++], s[i++]);
    while(j <= right) strcpy(temp[k++], s[j++]);
    for(int a = left; a <= right; a++) strcpy(s[a], temp[a]);
}

void mergeSort(char s[][51], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        mergeSort(s, left, mid);
        mergeSort(s, mid+1, right);
        merge(s, left, mid, right);
    }
}

int main() {
    int N;
    char s[20000][51];
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%s", s[i]);
    }
    mergeSort(s, 0, N-1);
    for(int i=0; i<N; i++) {
        if(i==0||(i>0&&strcmp(s[i],s[i-1])!=0))
            printf("%s\n", s[i]);
    }

    return 0;
}