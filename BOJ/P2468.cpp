#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e2 + 1

int land[MAX][MAX];
int check[MAX][MAX];
int temp[MAX][MAX];
int line;
int max_height;
int max_land;
int temp_land;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void DFS(int x, int y) {
	check[x][y] = false;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= line || ny >= line) {
			continue;
		}

		if (check[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

void Input() {
	cin >> line;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < line; j++) {
			cin >> land[i][j];

			if (max_height < land[i][j]) {
				max_height = land[i][j];
			}
		}
	}

	for (int k = max_height; k >= 1; k--) {
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < line; j++) {
				if (land[i][j] >= k) {
					check[i][j] = 1;
				}
			}
		}

		temp_land = 0;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < line; j++) {
				if (check[i][j]) {
					temp_land++;
					DFS(i, j);
				}
			}
		}

		max_land = max(max_land, temp_land);

		memset(check, false, sizeof(check));
	}
}

void Solution(void) {
	cout << max_land << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}