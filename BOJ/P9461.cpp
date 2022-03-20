#include <iostream>
using namespace std;

unsigned long long p[102];

unsigned long long Padoban(int number) {
	if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 1;
	}
	else if (number == 3) {
		return 1;
	}
	else {
		if (p[number] != 0) {
			return p[number];
		}
		else {
			p[number] = Padoban(number - 3) + Padoban(number - 2);
			return p[number];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int TestCount;
	cin >> TestCount;
	int number;
	while (TestCount != 0) {
		cin >> number;
		cout << Padoban(number) << '\n';
		TestCount--;
	}

	return 0;
}