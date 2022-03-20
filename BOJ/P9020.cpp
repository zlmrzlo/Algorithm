#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
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
	int testCase;
	cin >> testCase;

	int index = 0;
	vector<pair<int, int>> answer(testCase);
	while (testCase > 0) {
		cin >> input;
		int mid = input / 2;
		while (mid > 1) {
			while (!prime[mid]) {
				mid--;
			}
			if (mid <= 1) {
				break;
			}

			if (prime[input - mid]) {
				answer[index].first = mid;
				answer[index++].second = input - mid;
				break;
			}
			mid--;
		}
		testCase--;
	}

	for (int i = 0; i < index - 1; i++) {
		cout << answer[i].first << " " << answer[i].second << '\n';
	}
	cout << answer[index - 1].first << " " << answer[index - 1].second;

	return 0;
}