#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 2000

int n1, n2;
vector<int> v1[MAX];
vector<bool> v2;
void Input() {
	cin >> n1 >> n2;

	v2.resize(n1);

	int n3, n4;
	for (int i = 0; i < n2; i++) {
		cin >> n3 >> n4;
		v1[n3].push_back(n4);
		v1[n4].push_back(n3);
	}
}

bool n5;
void DFS(int count, int node) {
	if (count == 4) {
		n5 = true;
		return;
	}

	v2[node] = true;
	for (int i = 0; i < v1[node].size(); i++) {
		int next = v1[node][i];
		if (!v2[next]) {
			DFS(count + 1, next);
		}
	}
	v2[node] = false;
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		fill(v2.begin(), v2.end(), false);
		DFS(0, i);
		if (n5) {
			break;
		}
	}
	cout << n5 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}