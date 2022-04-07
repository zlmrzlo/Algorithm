#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 20001
#define RED 1
#define BLUE 2

int n1, n2, n3;
vector<int> v1[MAX];
vector<int> v2; 

void Input() {
}

void BFS(int start) {
	queue<int> q1;
	q1.push(start);
	int color = RED;
	v2[start] = color;

	while (!q1.empty()) {
		int node = q1.front();
		q1.pop();

		if (v2[node] == RED) {
			color = BLUE;
		}
		else if(v2[node] == BLUE){
			color = RED;
		}

		for (int i = 0; i < v1[node].size(); i++) {
			int next = v1[node][i];
			if (!v2[next]) {
				q1.push(next);
				v2[next] = color;
			}
		}
	}
}

void DFS(int start) {
	if (!v2[start]) {
		v2[start] = RED;
	}

	for (int i = 0; i < v1[start].size(); i++) {
		int next = v1[start][i];
		if (!v2[next]) {
			if (v2[start] == RED) {
				v2[next] = BLUE;
			}
			else if (v2[start] == BLUE) {
				v2[next] = RED;
			}
			DFS(next);
		}
	}
}

void Solution(void) {
	cin >> n1;
	while (n1--) {
		cin >> n2 >> n3;
		v2.resize(n2 + 1);

		int n4, n5;
		for (int i = 0; i < n3; i++) {
			cin >> n4 >> n5;
			v1[n4].push_back(n5);
			v1[n5].push_back(n4);
		}

		for (int i = 1; i <= n2; i++) {
			sort(v1[i].begin(), v1[i].end());
		}

		for (int i = 1; i <= n2; i++) {
			if (!v2[i]) {
				BFS(i);
			}
		}

		bool b1 = false;
		for (int i = 1; i <= n2; i++) {
			for (int j = 0; j < v1[i].size(); j++) {
				int next = v1[i][j];
				if (v2[i] == v2[next]) {
					b1 = true;
					break;
				}
			}
		}
		b1 ? cout << "NO" << endl : cout << "YES" << endl;

		for (int i = 1; i <= n2; i++) {
			v1[i].clear();
		}

		fill(v2.begin(), v2.end(), false);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}