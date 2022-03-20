#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;

	while (number != 0) {
		if (number == 1) {
			break;
		}
		for (int i = 2; i <= number; i++) {
			if (number % i == 0) {
				cout << i << endl;
				number /= i;
				i--;
			}
		}
	}
	return 0;
}