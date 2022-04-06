#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1001

int n1, n2, n3;
vector<int> v1[MAX];
vector<bool> v2;
void Input() {
	cin >> n1 >> n2 >> n3;
	v2.resize(n1 + 1);

	int n4, n5;
	for (int i = 0; i < n2; i++) {
		cin >> n4 >> n5;
		v1[n4].push_back(n5);
		v1[n5].push_back(n4);
	}

	for (int i = 1; i <= n1; i++) {
		sort(v1[i].begin(), v1[i].end());
	}
}

void DFS(int start) {
	v2[start] = true;
	cout << start << ' ';

	for (int i = 0; i < v1[start].size(); i++) {
		int node = v1[start][i];
		if (!v2[node]) {
			DFS(node);
		}
	}
}

void BFS(int start) {
	queue<int> q1;
	q1.push(start);
	v2[start] = true;

	while (!q1.empty()) {
		int node = q1.front();
		q1.pop();
		cout << node << ' ';
		for (int i = 0; i < v1[node].size(); i++) {
			int next = v1[node][i];
			if (!v2[next]) {
				q1.push(next);
				v2[next] = true;
			}
		}
	}
}

void Solution(void) {
	DFS(n3);
	cout << endl;
	fill(v2.begin(), v2.end(), false);
	BFS(n3);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}