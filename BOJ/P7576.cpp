#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1000

int a1[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n1, n2;
queue<pair<int, int>> q1;

void Input() {
	cin >> n2 >> n1;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			cin >> a1[i][j];
			if (a1[i][j] == 1) {
				q1.push(make_pair(i, j));
			}
		}
	}
}

void BFS() {
	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();

		for (size_t i = 0; i < 4; i++) {
			int nx = p1.first + dx[i];
			int ny = p1.second + dy[i];

			if (nx < 0 || nx >= n1 || ny < 0 || ny >= n2) {
				continue;
			}

			if (a1[nx][ny] == 0) {
				a1[nx][ny] = a1[p1.first][p1.second] + 1;
				q1.push(make_pair(nx, ny));
			}
		}
	}
}

void Solution(void) {
	BFS();

	int n3 = 0;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (a1[i][j] == 0) {
				cout << -1 << endl;
				return;
			}

			if (n3 < a1[i][j]) {
				n3 = a1[i][j];
			}
		}
	}

	cout << n3 - 1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}