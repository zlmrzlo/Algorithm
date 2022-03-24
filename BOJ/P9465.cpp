#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 100001

int a1[3][MAX];
int a2[3][MAX];
void Solution(void) {
	int n1;
	cin >> n1;

	while (n1--) {
		int n2;
		cin >> n2;

		for (int j = 1; j <= 2; j++) {
			for (int i = 1; i <= n2; i++) {
				cin >> a1[j][i];
			}
		}

		a2[1][1] = a1[1][1];
		a2[2][1] = a1[2][1];
		for (int i = 2; i <= n2; i++) {
			a2[1][i] = max(a2[2][i - 1], a2[2][i - 2]) + a1[1][i];
			a2[2][i] = max(a2[1][i - 1], a2[1][i - 2]) + a1[2][i];
		}

		cout << max(a2[1][n2], a2[2][n2]) << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í: https://ongveloper.tistory.com/265