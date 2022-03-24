#include <bits/stdc++.h>
using namespace std;

#define MAX 201
#define MOD 1000000000
long long a1[MAX][MAX];
void Solution(void) {
	int n1, n2;
	cin >> n1 >> n2;

	for (int i = 0; i <= n1; i++) {
		a1[1][i] = 1;
	}

	for (int k = 2; k <= n2; k++) {
		for (int i = 0; i <= n1; i++) {
			for (int j = 0; j <= i; j++) {
				a1[k][i] += a1[k - 1][j];
				a1[k][i] %= MOD;
			}
		}
	}

	cout << a1[n2][n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://yabmoons.tistory.com/128