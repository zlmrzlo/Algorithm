#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 10001;

void CreatePrime(bool* prime) {
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= SIZE - 1; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	bool prime[SIZE];
	memset(prime, true, SIZE * sizeof(bool));
	prime[0] = false;
	prime[1] = false;

	CreatePrime(prime);

	int count;
	int input;
	while (true) {
		count = 0;
		cin >> input;
		for (int i = input + 1; i <= input * 2; i++) {
			if (prime[i]) {
				count++;
			}
		}
		if (count == 0) {
			break;
		}
		cout << count << endl;
	}

	return 0;
}