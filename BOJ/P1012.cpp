#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 50 + 1

int test_case;
int land[MAX][MAX];
int check[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int width, height;
int bug_count;
int answer;

void DFS(int x, int y) {
	check[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= height || ny >= width) {
			continue;
		}

		if (check[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

void Input() {
	cin >> test_case;

	while (test_case--) {
		cin >> width >> height;
		cin >> bug_count;

		int x, y;
		answer = 0;

		for (int i = 0; i < bug_count; i++) {
			cin >> x >> y;
			land[y][x] = 1;
			check[y][x] = 1;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (check[i][j]) {
					answer++;
					DFS(i, j);
				}
			}
		}

		memset(land, 0, sizeof(land));
		memset(check, 0, sizeof(check));

		cout << answer << endl;
	}
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}