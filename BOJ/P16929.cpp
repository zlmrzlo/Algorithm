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

void BFS(int x, int y) {
	queue<pair<int, int>> q1;
	q1.push(make_pair(x, y)); 
	a2[x][y] = 1;

	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int nx = p1.first + dx[i];
			int ny = p1.first + dy[i];

			if (nx < 0 || nx >= n1 || ny < 0 || ny >= n2) {
				continue;
			}

			if (a2[nx][ny] == 0 && a1[x][y] == a1[p1.first][p1.second]) {
				a2[nx][ny] = a2[p1.first][p1.second] + 1;
				q1.push({ nx,ny });
			}
		}
	}
}

bool b1;
void Solution(void) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (!a2[i][j]) {
				BFS(i, j);
			}
			for (int k = 0; k < n1; k++) {
				for (int l = 0; l < n2; l++) {
					cout << a2[k][l] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			memset(a2, false, sizeof(a2));
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