#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 3001

int n1;
vector<int> v1[MAX];
bool a1[MAX];
bool a2[MAX];
int a3[MAX];

void Input() {
	cin >> n1;
	int n2, n3;
	for (int i = 0; i < n1; i++) {
		cin >> n2 >> n3;
		v1[n2].push_back(n3);
		v1[n3].push_back(n2);
	}
}

bool b1;
void DFS(int count, int start, int current) {
	if (start == current && count >= 3) {
		b1 = true;
		return;
	}
	a1[current] = true;

	for (int i = 0; i < v1[current].size(); i++) {
		int next = v1[current][i];
		if (!a1[next]) {
			DFS(count + 1, start, next);
		}
		else if (start == next && count >= 3) {
			DFS(count, start, next);
		}
	}
}

int BFS(int start) {
	memset(a1, false, sizeof(a1));
	queue<pair<int, int>> q1;
	q1.push(make_pair(start, 0));
	a1[start] = true;

	while (!q1.empty()) {
		pair<int, int> p1 = q1.front();
		q1.pop();

		if (a2[p1.first]) {
			return p1.second;
		}

		for (int i = 0; i < v1[p1.first].size(); i++) {
			int next = v1[p1.first][i];
			if (!a1[next]) {
				a1[next] = true;
				q1.push(make_pair(next, p1.second + 1));
			}
		}
	}
}

void Solution(void) {
	for (int i = 1; i <= n1; i++) {
		memset(a1, false, sizeof(a1));
		b1 = false;
		DFS(1, i, i);
		if (b1) {
			a2[i] = true;
		}
	}

	vector<int> v2;
	for (int i = 1; i <= n1; i++) {
		if (!a2[i]) {
			v2.push_back(BFS(i));
		}
		else {
			v2.push_back(0);
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}