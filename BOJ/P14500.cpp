#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 500

int a1[MAX][MAX];
bool a2[MAX][MAX];
int n1, n2;
int n3;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void Input() {
	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			cin >> a1[i][j];
		}
	}
}

void DFS(int x, int y, int sum, int count) {
	a2[x][y] = true;

	if (count == 3) {
		n3 = max(n3, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n1 || ny >= n2) {
			continue;
		}
		if (a2[nx][ny] == true) {
			continue;
		}

		DFS(nx, ny, sum + a1[nx][ny], count + 1);
		a2[nx][ny] = false;
	}
}

void WayOne(int x, int y) {
	int s1 = a1[x][y] + a1[x][y - 1] + a1[x][y + 1] + a1[x - 1][y];
	n3 = max(n3, s1);
}

void WayTwo(int x, int y) {
	int s1 = a1[x][y] + a1[x][y - 1] + a1[x + 1][y] + a1[x - 1][y];
	n3 = max(n3, s1);
}

void WayThree(int x, int y) {
	int s1 = a1[x][y] + a1[x][y + 1] + a1[x][y - 1] + a1[x + 1][y];
	n3 = max(n3, s1);
}

void WayFour(int x, int y) {
	int s1 = a1[x][y] + a1[x + 1][y] + a1[x][y + 1] + a1[x - 1][y];
	n3 = max(n3, s1);
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			memset(a2, false, sizeof(a2));
			DFS(i, j, a1[i][j], 0);
			if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < n2) {
				WayOne(i, j);
			}
			if (i - 1 >= 0 && i + 1 < n1 && j - 1 >= 0) {
				WayTwo(i, j);
			}
			if (i + 1 < n1 && j - 1 >= 0 && j + 1 < n2) {
				WayThree(i, j);
			}
			if (j + 1 < n2 && i + 1 < n1 && i - 1 >= 0) {
				WayFour(i, j);
			}
		}
	}

	cout << n3 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}