#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 300

int a1[MAX][MAX];

int n1, n2;
pair<int, int> p1;
pair<int, int> p2;
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

void Input() {
}

bool b1;
void BFS(int x, int y) {
	queue<pair<int, int>> q1;
	q1.push(make_pair(x, y));

	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();
		if (p1.first == p2.first && p1.second == p2.second) {
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = p1.first + dx[i];
			int ny = p1.second + dy[i];

			if (nx < 0 || nx >= n2 || ny < 0 || ny >= n2) {
				continue;
			}

			if (!a1[nx][ny]) {
				a1[nx][ny] = a1[p1.first][p1.second] + 1;
				q1.push({ nx, ny });
			}
		}
	}
}

void Solution(void) {
	cin >> n1;
	while (n1--) {
		cin >> n2;
		cin >> p1.first >> p1.second;
		cin >> p2.first >> p2.second;

		BFS(p1.first, p1.second);

		cout << a1[p2.first][p2.second] << endl;

		memset(a1, false, sizeof(a1));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}