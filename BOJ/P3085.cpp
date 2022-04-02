#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 50

int n1;
char a1[MAX][MAX];
int n2;
void Input() {
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			cin >> a1[i][j];
		}
	}
}

void check() {
	char c1;
	for (int i = 0; i < n1; i++) {
		c1 = a1[i][0];
		int count = 1;
		for (int j = 1; j < n1; j++) {
			if (a1[i][j] == c1) {
				count++;
			}
			else {
				count = 1;
			}
			c1 = a1[i][j];
			n2 = max(n2, count);
		}
	}

	for (int j = 0; j < n1; j++) {
		c1 = a1[0][j];
		int count = 1;
		for (int i = 1; i < n1; i++) {
			if (a1[i][j] == c1) {
				count++;
			}
			else {
				count = 1;
			}
			c1 = a1[i][j];
			n2 = max(n2, count);
		}
	}
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1 - 1; j++) {
			swap(a1[i][j], a1[i][j + 1]);
			check();
			swap(a1[i][j], a1[i][j + 1]);
		}
	}

	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < n1 - 1; i++) {
			swap(a1[i][j], a1[i + 1][j]);
			check();
			swap(a1[i][j], a1[i + 1][j]);
		}
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}