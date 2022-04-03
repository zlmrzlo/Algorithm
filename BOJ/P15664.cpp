#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1, n2;
vector<int> v1;
vector<int> v2;
vector<bool> v3;
void Input() {
	cin >> n1 >> n2;
	v1.resize(n1);
	v2.resize(n1);
	v3.resize(n1);
	for (int i = 0; i < n1; i++) {
		int n3;
		cin >> n3;
		v1[i] = n3;
	}
	sort(v1.begin(), v1.end());
}

void DFS(int count, int before) {
	if (count == n2) {
		for (int i = 0; i < n2; i++) {
			cout << v2[i] << ' ';
		}
		cout << endl;
		return;
	}

	int n4 = 0;
	for (int i = 0; i < v1.size(); i++) {
		if (!v3[i] && v1[i] != n4 && before <= v1[i]) {
			v3[i] = true;
			v2[count] = v1[i];
			n4 = v1[i];
			DFS(count + 1, v1[i]);
			v3[i] = false;
		}
	}
}

void Solution(void) {
	DFS(0, 0);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}