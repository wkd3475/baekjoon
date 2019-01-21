#include <iostream>

using namespace std;

int main() {
    int n, count = 0;
    int val;
    cin>>n;

    val = n;

    while(1) {
        int a, b, c; // a + b = c
        count ++;
        a = val / 10;
        b = val % 10;

        c = a + b;
        val = b * 10 + c % 10;

        if(val == n)
            break;
    }

    printf("%d\n", count);
}