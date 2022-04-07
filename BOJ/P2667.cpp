#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 25

int a1[MAX][MAX];
bool a2[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n1;
void Input() {
	cin >> n1;
	string s1;
	for (int i = 0; i < n1; i++) {
		cin >> s1;
		for (int j = 0; j < s1.size(); j++) {
			a1[i][j] = s1[j] - '0';
		}
	}
}

int n2;
void DFS(int x, int y) {
	a2[x][y] = true; 
	n2++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n1 || ny >= n1) {
			continue;
		}

		if (!a2[nx][ny] && a1[nx][ny]) {
			DFS(nx, ny);
		}
	}

}

vector<int> v1;
void Solution(void) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			if (!a2[i][j] && a1[i][j]) {
				n2 = 0;
				DFS(i, j);
				v1.push_back(n2);
			}
		}
	}
	cout << v1.size() << endl;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}