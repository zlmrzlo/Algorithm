#include <iostream>
using namespace std;

int Fibonacci(int number) {
	if (number == 0) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}
	return Fibonacci(number - 1) + Fibonacci(number - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int number;
	cin >> number;

	cout << Fibonacci(number) << endl;

	return 0;
}