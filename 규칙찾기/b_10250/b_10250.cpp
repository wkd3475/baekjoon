#include <stdio.h>

// number of room => W
// floor => H
// customer num => N

int main() {
    int T, H, W, N;
    int num_floor, num_room;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &H, &W, &N);
        num_floor = (N % H != 0 ? N % H : H);
        num_room = (N % H != 0 ? N / H + 1 : N / H);
        printf("%d\n", num_floor * 100 + num_room);
    }
}