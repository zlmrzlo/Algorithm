#include <iostream>
using namespace std;

int Factorial(int number) {
	if (number == 1) {
		return 1;
	}
	if (number == 0) {
		return 1;
	}
	return number * Factorial(number - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int number;
	cin >> number;

	cout << Factorial(number) << endl;

	return 0;
}