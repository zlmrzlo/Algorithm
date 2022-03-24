#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 501

int a1[MAX][MAX];
int a2[MAX][MAX];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a1[i][j];
		}
	}

	a2[1][1] = a1[1][1];
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				a2[i][j] = a2[i - 1][j] + a1[i][j];
			}
			else if (j >= 2 && j <= i - 1) {
				a2[i][j] = max(a2[i - 1][j - 1], a2[i - 1][j]) + a1[i][j];
			}
			else {
				a2[i][j] = a2[i - 1][i - 1] + a1[i][i];
			}
		}
	}

	int n2 = 0;
	for (int i = 1; i <= n1; i++) {
		if (n2 < a2[n1][i]) {
			n2 = a2[n1][i];
		}
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}