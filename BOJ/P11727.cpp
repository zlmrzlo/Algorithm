#include <bits/stdc++.h>
using namespace std;

int a1[1001];
void Solution(void) {
	int n1;
	cin >> n1;

	a1[1] = 1;
	a1[2] = 3;

	for (int i = 3; i <= n1; i++) {
		a1[i] = (a1[i - 1] + a1[i - 2] + a1[i - 2]) % 10007;
	}

	cout << a1[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}