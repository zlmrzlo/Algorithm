#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n1) {
	for (int i = 2; i <= sqrt(n1); i++) {
		if (n1 % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);
	int n1, n2, n3, n4;
	while (true) {
		cin >> n1;

		if (n1 == 0) {
			break;
		}

		for (int i = 1; i < n1 / 2; i++) {
			n3 = 2 * i + 1;
			n4 = n1 - n3;
			if (IsPrime(n3) and IsPrime(n4)) {
				cout << n1 << " = " << n3 << " + " << n4 << "\n";
				break;
			}
		}
	}

	return 0;
}

// Âü°í: https://ijsilver.tistory.com/44