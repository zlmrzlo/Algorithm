#include <bits/stdc++.h>
using namespace std;

int a1[100001];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		a1[i] = i;
		for (int j = 1; j * j <= i; j++) {
			a1[i] = min(a1[i], a1[i - j * j] + 1);
		}
	}

	cout << a1[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://guiyum.tistory.com/17