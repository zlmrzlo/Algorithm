#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 100001
#define MOD 9901

int a1[MAX][3];
void Solution(void) {
	int n1;
	cin >> n1;

	a1[1][0] = 1;
	a1[1][1] = 1;
	a1[1][2] = 1;
	for (int i = 2; i < MAX; i++) {
		a1[i][0] = (a1[i - 1][0] + a1[i - 1][1] + a1[i - 1][2]) % MOD;
		a1[i][1] = (a1[i - 1][0] + a1[i - 1][2]) % MOD;
		a1[i][2] = (a1[i - 1][0] + a1[i - 1][1]) % MOD;
	}

	cout << (a1[n1][0] + a1[n1][1] + a1[n1][2]) % MOD << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}
