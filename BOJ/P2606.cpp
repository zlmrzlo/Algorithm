#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e2 + 1

vector<int> v1[MAX];
vector<int> v2;
int computer_count;
int computer_connect;

void Input() {
	cin >> computer_count >> computer_connect;

	int start, end;
	v2.resize(computer_count + 1);

	for (int i = 0; i < computer_connect; i++) {
		cin >> start >> end;
		v1[start].push_back(end);
		v1[end].push_back(start);
	}
}

int node_count;
void DFS(int start) {
	v2[start] = true;

	for (int i = 0; i < v1[start].size(); i++) {
		int node = v1[start][i];

		if (!v2[node]) {
			node_count++;
			DFS(node);
		}
	}
}

void Solution(void) {
	DFS(1);
	cout << node_count << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}