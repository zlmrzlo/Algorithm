#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 50
int n1, n2;
char a1[MAX][MAX];
int a2[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Input() {
	cin >> n1 >> n2;
	string s1;
	for (int i = 0; i < n1; i++) {
		cin >> s1;
		for (int j = 0; j < n2; j++) {
			a1[i][j] = s1[j];
		}
	}
}

bool b1;
void DFS(int count, int x, int y, int sx, int sy) {
	a2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n1 || ny >= n2) {
			continue;
		}

		if (a1[x][y] == a1[nx][ny] && !a2[nx][ny]) {
			DFS(count + 1, nx, ny, sx, sy);
		}
		else if (sx == nx && sy == ny && count >= 4) {
			b1 = true;
			return;
		}

	}
	a2[x][y] = false;
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			DFS(1, i, j, i, j);
		}
	}

	b1 ? cout << "Yes" << endl : cout << "No" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}