#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1001

int n1, n2;
vector<int> v1[MAX];
vector<bool> v2;
void Input() {
	cin >> n1 >> n2;
	v2.resize(n1 + 1);

	int n3, n4;
	for (int i = 0; i < n2; i++) {
		cin >> n3 >> n4;
		v1[n3].push_back(n4);
		v1[n4].push_back(n3);
	}

	for (int i = 1; i <= n1; i++) {
		sort(v1[i].begin(), v1[i].end());
	}
}

void DFS(int node) {
	v2[node] = true;
	for (int i = 0; i < v1[node].size(); i++) {
		int next = v1[node][i];
		if (!v2[next]) {
			DFS(next);
		}
	}
}

int n5 = 0;
void Solution(void) {
	for (int i = 1; i <= n1; i++) {
		if (!v2[i]) {
			DFS(i);
			n5++;
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