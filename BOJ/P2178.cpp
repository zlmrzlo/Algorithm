#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 100

int n1, n2;
int a1[MAX][MAX];
int a3[MAX][MAX];
bool a2[MAX][MAX];
int n3;
int dx[4] = {-1, 0, 1, 0 };
int dy[4] = {0, 1, 0, -1 };

void Input() {
	cin >> n1 >> n2;
	n3 = n1 * n2 + 1;
	string s1;
	for (int i = 0; i < n1; i++) {
		cin >> s1;
		for (int j = 0; j < n2; j++) {
			a1[i][j] = s1[j] - '0';
		}
	}
}


void DFS(int count, int x, int y) {
	if (x < 0 || y < 0 || x >= n1 || y >= n2) {
		return;
	}
	if (x == n1 - 1 && y == n2 - 1) {
		n3 = min(n3, count);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!a2[nx][ny] && a1[nx][ny]) {
			a2[nx][ny] = true;
			DFS(count + 1, nx, ny);
			a2[nx][ny] = false;
		}
	}
}

void BFS(int x, int y) {
	queue<pair<int, int>> q1;
	q1.push(make_pair(x, y));
	a2[x][y] = true;

	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int nx = p1.first + dx[i];
			int ny = p1.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n1 || ny >= n2) {
				continue;
			}

			if (!a2[nx][ny] && a1[nx][ny]) {
				a3[nx][ny] = a3[p1.first][p1.second] + 1;
				a2[nx][ny] = true;
				q1.push(make_pair(nx, ny));
			}
		}
	}
}

void Solution(void) {
	BFS(0, 0);
	cout << a3[n1 - 1][n2 - 1] + 1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}