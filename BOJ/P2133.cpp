#include <bits/stdc++.h>
using namespace std;

int a1[31];
void Solution(void) {
	int n1;
	cin >> n1;

	if (n1 % 2) {
		cout << '0' << endl;
		return;
	}

	a1[0] = 1;
	a1[2] = 3;
	for (int i = 4; i <= n1; i += 2) {
		a1[i] = a1[i - 2] * a1[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			a1[i] += a1[j] * 2;
		}
	}

	cout << a1[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}