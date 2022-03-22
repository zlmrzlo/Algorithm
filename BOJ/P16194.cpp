#include <bits/stdc++.h>
using namespace std;

int a1[1001];
int a2[1001];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i];
		a2[i] = a1[i];
	}

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= i; j++) {
			a2[i] = min(a2[i], a2[i - j] + a1[j]);
		}
	}

	cout << a2[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://dandalf.tistory.com/59