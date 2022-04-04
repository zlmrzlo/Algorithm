#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
vector<int> v1;
vector<bool> v2;
vector<int> v3;
void Input() {
}

void DFS(int count, int next) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v3[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = next; i < n1; i++) {
		if (!v2[i]) {
			v2[i] = true;
			v3[count] = v1[i];
			DFS(count + 1, i + 1);
			v2[i] = false;
		}
	}
}

void Solution(void) {
	while (true) {
		cin >> n1;

		if (n1 == 0) {
			break;
		}

		v1.resize(n1);
		v2.resize(n1);
		v3.resize(n1);
		for (int i = 0; i < n1; i++) {
			int n2;
			cin >> n2;
			v1[i] = n2;
		}

		DFS(0, 0);
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}