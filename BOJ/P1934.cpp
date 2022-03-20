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
	int n3;
	cin >> n3;
	while (n3--) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << LCM(n1, n2) << '\n';
	}
}