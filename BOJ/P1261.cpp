#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e2

int n1, n2;
int a1[MAX][MAX];
int a2[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Input() {
	cin >> n1 >> n2;
	string s1;
	for (int i = 0; i < n2; i++) {
		cin >> s1;
		for (int j = 0; j < s1.size(); j++) {
			a1[i][j] = s1[j] - '0';
			a2[i][j] = 1e8;
		}
	}
}

void Solution(void) {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	a2[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n2 || ny >= n1) {
				continue;
			}

			if (a1[nx][ny] == 1) {
				if (a2[nx][ny] > a2[x][y] + 1) {
					a2[nx][ny] = a2[x][y] + 1;
					q.push({ nx, ny });
				}
			}
			else if (a1[nx][ny] == 0) {
				if (a2[nx][ny] > a2[x][y]) {
					a2[nx][ny] = a2[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << a2[n2 - 1][n1 - 1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}