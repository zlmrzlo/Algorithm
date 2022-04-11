#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e4 + 1

int node_size;
vector<pair<int, int>> node[MAX];
int low[MAX];
int high[MAX];
int root_node[MAX];
int root;
int index_number;

void Input() {
	cin >> node_size;
	int parent_node, left_node, right_node;
	for (int i = 1; i <= node_size; i++) {
		cin >> parent_node >> left_node >> right_node;
		root_node[parent_node]++;

		if (left_node != -1) {
			root_node[left_node]++;
		}
		if (right_node != -1) {
			root_node[right_node]++;
		}

		node[parent_node].push_back({ left_node, right_node });
	}

	for (int i = 1; i <= node_size; i++) {
		if (root_node[i] == 1) {
			root = i;
		}
	}
}

void DFS(int current_node, int count) {
	if (current_node == -1) {
		return;
	}

	if (node[current_node].front().first > 0) {
		DFS(node[current_node].front().first, count + 1);
	}

	low[count] = min(low[count], index_number);
	high[count] = max(high[count], index_number++);

	if (node[current_node].front().second > 0) {
		DFS(node[current_node].front().second, count + 1);
	}
}

void Solution(void) {
	index_number = 1;
	for (int i = 1; i <= node_size; i++) {
		low[i] = (int)1e9;
	}
	DFS(root, 1);

	int result = high[1] - low[1] + 1;
	int depth = 1;

	for (int i = 2; i <= node_size; i++) {
		int temp = high[i] - low[i] + 1;
		if (result < temp) {
			result = temp;
			depth = i;
		}
	}

	cout << depth << ' ' << result << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}