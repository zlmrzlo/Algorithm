#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1001
#define MOD 10007

int a1[MAX][10];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 0; i <= 9; i++) {
		a1[1][i] = 1;
	}

	for (int i = 2; i <= n1; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				a1[i][j] += a1[i - 1][k];
				a1[i][j] %= MOD;
			}
		}
	}

	int n2 = 0;
	for (int i = 0; i <= 9; i++) {
		n2 += a1[n1][i];
	}

	cout << n2 % MOD << endl;

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://yabmoons.tistory.com/62