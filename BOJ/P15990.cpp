#include <bits/stdc++.h>
using namespace std;

long long a1[100001][4];
void Solution(void) {
	int n1;
	cin >> n1;

	a1[1][1] = a1[2][2] = a1[3][1] = a1[3][2] = a1[3][3] = 1;
	for (int i = 4; i < 100001; i++) {
		if (i - 1 >= 0) {
			a1[i][1] = (a1[i - 1][2] + a1[i - 1][3]) % 1000000009;
		}
		if (i - 2 >= 0) {
			a1[i][2] = (a1[i - 2][1] + a1[i - 2][3]) % 1000000009;
		}
		if (i - 3 >= 0) {
			a1[i][3] = (a1[i - 3][2] + a1[i - 3][1]) % 1000000009;
		}
	}

	while (n1--) {
		int n2;
		cin >> n2;
		cout << (a1[n2][1] + a1[n2][2] + a1[n2][3]) % 1000000009 << endl;
	}

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://jdselectron.tistory.com/71