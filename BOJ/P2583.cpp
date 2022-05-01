#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e2 + 1

int height, width, rect_count;
int board[MAX][MAX];

void Input() {
	cin >> height >> width >> rect_count;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j] = 1; 
		}
	}

	int start_x, start_y, end_x, end_y;

	while (rect_count--) {
		cin >> start_x >> start_y >> end_x >> end_y;
		for (int i = start_x; i < end_x; i++) {
			for (int j = start_y; j < end_y; j++) {
				if (board[j][i]) {
					board[j][i] = 0;
				}
			}
		}
	}
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int area_count;

void DFS(int x, int y) {
	board[x][y] = 0;
	area_count++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= height || ny >= width) {
			continue;
		}

		if (board[nx][ny]) {
			DFS(nx, ny);
		}
	}

}

void Solution(void) {
	int total_count = 0;
	vector<int> count_vector;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j]) {
				DFS(i, j);
				total_count++;
				count_vector.push_back(area_count);
				area_count = 0;
			}
		}
	}

	cout << total_count << endl;
	sort(count_vector.begin(), count_vector.end());
	for (int i = 0; i < count_vector.size(); i++) {
		cout << count_vector[i] << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}