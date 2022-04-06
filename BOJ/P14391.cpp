#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 5

int n1, n2;
int a1[MAX][MAX];
bool a2[MAX][MAX];
int n3;
void Input() {
	cin >> n1 >> n2;
	string s1;
	for (int i = 0; i < n1; i++) {
		cin >> s1;
		for (int j = 0; j < n2; j++) {
			a1[i][j] = s1[j] - '0';
		}
	}
}

void DFS(int row, int col) {
	if (row == n1) {
		int n5 = 0;
		for (int i = 0; i < n1; i++) {
			int n4 = 0;
			for (int j = 0; j < n2; j++) {
				if (a2[i][j]) {
					n4 *= 10;
					n4 += a1[i][j];
				}
				else {
					n5 += n4;
					n4 = 0;
				}
			}
			n5 += n4;
		}

		for (int j = 0; j < n2; j++) {
			int n4 = 0;
			for (int i = 0; i < n1; i++) {
				if (!a2[i][j]) {
					n4 *= 10;
					n4 += a1[i][j];
				}
				else {
					n5 += n4;
					n4 = 0;
				}
			}
			n5 += n4;
		}
		n3 = max(n3, n5);
		return;
	}

	if (col == n2) {
		DFS(row + 1, 0);
		return;
	}
	a2[row][col] = true;
	DFS(row, col + 1);
	a2[row][col] = false;
	DFS(row, col + 1);
}

void Solution(void) {
	DFS(0, 0);
	cout << n3 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}