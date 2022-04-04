#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
vector<int> v1;
vector<bool> v2;
vector<int> v3;
void Input() {
	cin >> n1;

	v1.resize(n1);
	v2.resize(n1);
	v3.resize(n1);
	for (int i = 0; i < n1; i++) {
		v1[i] = i + 1;
	}
}

void DFS(int count) {
	if (count == n1) {
		for (int i = 0; i < n1; i++) {
			cout << v3[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n1; i++) {
		if (!v2[i]) {
			v2[i] = true;
			v3[count] = v1[i];
			DFS(count + 1);
			v2[i] = false;
		}
	}
}

void Solution(void) {
	DFS(0);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}