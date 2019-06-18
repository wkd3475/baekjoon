#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int *temp = a;
	a = b;
	b = temp;
}

int gcd(int a, int b) {
	int c;
	while(b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int T;

	cin>>T;

	for(int i=0; i<T; i++) {
		int a, b, c;
		cin>>a>>b;
		if(a<b)
			swap(&a,&b);

		c = gcd(a,b);
		printf("%d\n", a*b/c);
	}
}
