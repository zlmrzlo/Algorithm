#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
#define MOD 1000000009
long long a1[1000001];
void Solution(void) {
	int t1;
	cin >> t1;

	a1[1] = 1;
	a1[2] = 2;
	a1[3] = 4;
	for (int i = 4; i < MAX; i++) {
		a1[i] = a1[i - 1] + a1[i - 2] + a1[i - 3];
		a1[i] %= MOD;
	}

	while (t1--) {
		int n1;
		cin >> n1;
		cout << a1[n1] << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}