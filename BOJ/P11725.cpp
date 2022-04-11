#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 1

int node_size;
int node_a, node_b;
vector<int> tree[MAX];
int parent_tree[MAX];
bool parent_check[MAX];

void Input() {
	cin >> node_size;
	for (int i = 0; i < node_size - 1; i++) {
		cin >> node_a >> node_b;
		tree[node_a].push_back(node_b);
		tree[node_b].push_back(node_a);
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < tree[1].size(); i++) {
		q.push({ tree[1][i], 1 });
		parent_check[1] = true;
	}

	while (!q.empty()) {
		int current_node = q.front().first;
		int parent_node = q.front().second;
		q.pop();
		parent_check[current_node] = true;
		parent_tree[current_node] = parent_node;

		for (int i = 0; i < tree[current_node].size(); i++) {
			if (!parent_check[tree[current_node][i]]) {
				q.push({ tree[current_node][i], current_node });
			}
		}
	}

	for (int i = 2; i <= node_size; i++) {
		cout << parent_tree[i] << endl;
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