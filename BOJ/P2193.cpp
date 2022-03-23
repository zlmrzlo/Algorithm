#include <bits/stdc++.h>
using namespace std;

long long a1[91];
void Solution(void) {
	int n1;
	cin >> n1;

	a1[1] = 1;
	a1[2] = 1;
	for (int i = 3; i <= n1; i++) {
		a1[i] = a1[i - 1] + a1[i - 2];
	}

	cout << a1[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}