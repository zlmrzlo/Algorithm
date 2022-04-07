#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 50

int n1, n2;
int a1[MAX][MAX];
bool a2[MAX][MAX];
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
void Input() {
}

void BFS(int x, int y) {
	queue<pair<int,int>> q1;
	q1.push(make_pair(x, y));
	a2[x][y] = true;

	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();

		for (int i = 0; i < 8; i++) {
			int nx = p1.first + dx[i];
			int ny = p1.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n1 || ny >= n2) {
				continue;
			}

			if (a1[nx][ny] && !a2[nx][ny]) {
				a2[nx][ny] = true;
				q1.push(make_pair(nx, ny));
			}
		}
	}

}

void DFS(int x, int y) {
	a2[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n1 || ny >= n2) {
			continue;
		}

		if (!a2[nx][ny] && a1[nx][ny]) {
			a2[nx][ny] = true;
			BFS(nx, ny);
		}
	}
}

void Solution(void) {
	while (true) {
		cin >> n2 >> n1;
		if (n1 == 0 && n2 == 0) {
			break;
		}
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				cin >> a1[i][j];
			}
		}

		int n3 = 0;
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				if (!a2[i][j] && a1[i][j]) {
					BFS(i, j);
					n3++;
				}
			}
		}
		cout << n3 << endl;

		memset(a1, false, sizeof(a1));
		memset(a2, false, sizeof(a2));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}