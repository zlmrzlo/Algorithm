#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
int a1[101][10];

void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			a1[1][i] = 0;
		}
		else {
			a1[1][i] = 1;
		}
	}

	for (int i = 2; i <= n1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				a1[i][j] = a1[i - 1][j + 1] % MOD;
			}
			else if(j >= 1 && j <= 8) {
				a1[i][j] = (a1[i - 1][j - 1] + a1[i - 1][j + 1]) % MOD;
			}
			else {
				a1[i][j] = a1[i - 1][j - 1] % MOD;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += a1[n1][i];
		sum %= MOD;
	}

	cout << sum << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://ssinee.tistory.com/37