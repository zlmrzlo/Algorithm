#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	cout << GCD(n1, n2) << "\n" << LCM(n1, n2);
}

// Âü°í: https://sectumsempra.tistory.com/77